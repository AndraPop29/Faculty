/**
 * Created by andrapop on 2017-12-17.
 */
import mpi.*;
import java.io.InvalidObjectException;

public class hello {

    class VectorElement {
        public int Index;
        public int Value;
    }
    public static Polynomial RandomPolynomial(int degree) throws InvalidObjectException {
        if (degree < 0)
            throw new InvalidObjectException("Invalid degree specification!");
        List lista = new ArrayList<>();
        int[] coefficients = new int[degree + 1];

        for (int i = 0; i <= degree; ++i)
            coefficients[i] = R.nextInt(10);

        return new Polynomial(coefficients);
    }

    public static void main(String args[]) throws Exception {
        MPI.Init(args);

        var comm = MPI.COMM_WORLD;

        Polynomial x = null, y = null;
        int n;

        if (comm.Rank() == 0) // By convention the channel with index 0 is the master process.
        {
            final int degree = 100;
            x = RandomPolynomial(degree);
            y = RandomPolynomial(degree);

            n = degree + 1;

            int[] di = new int[n];
            int[][] dpq = new int[n][n];

            // Broadcast the polynomials to all slave processes so they know what they are working on.
            comm.Broadcast(ref x, 0);
            comm.Broadcast(ref y, 0);

            // Receive the computed element from the "di" vector.
            for (int i = 1; i <= n; ++i)
            {
                var result = comm.Receive<VectorElement>(Communicator.anySource, 1);
                di[result.Index] = result.Value;
            }

            // Receive the computed element from the "dpq" matrix.
            for (var i = 1; i <= n * (n - 1) / 2; ++i)
            {
                var result = comm.Receive<MatrixElement>(Communicator.anySource, 2);
                dpq[result.Row, result.Column] = result.Value;
            }

            var z = new int[2 * n - 1];
            z[0] = di[0];
            z[2 * n - 2] = di[n - 1];
            for (var i = 1; i <= 2 * n - 3; ++i)
            {
                for (var p = 0; p <= i; ++p)
                {
                    var q = i - p;
                    if (p < n && q < n && q > p)
                        z[i] += dpq[p, q] - (di[p] + di[q]);
                }

                if (i % 2 == 0)
                    z[i] += di[i / 2];
            }

            var output = new Polynomial(z);
            System.out.println(output);
            // System.out.println(Equals(x * y, output));
        }
        else // Otherwise it is a slave process.
        {
            // Receive the broadcasted polynomials.
            comm.Broadcast(ref x, 0);
            comm.Broadcast(ref y, 0);

            n = Math.Min(x.Degree, y.Degree) + 1;

            // The "for" lower and upper bounds.
            int workloadStart, workloadEnd;

            MpiFor(0, n - 1, 1, comm, out workloadStart, out workloadEnd);
            for (var i = workloadStart; i <= workloadEnd; ++i)
                comm.Send(new VectorElement {Index = i, Value = x.Coefficients[i] * y.Coefficients[i]}, 0, 1);

            MpiFor(0, 2 * n - 3, 1, comm, out workloadStart, out workloadEnd);
            for (var i = workloadStart; i <= workloadEnd; ++i)
                for (var p = 0; p <= i; ++p)
                {
                    var q = i - p;
                    if (p < n && q < n && q > p)
                        comm.Send(
                                new MatrixElement
                    {
                        Row = p,
                                Column = q,
                                Value =
                                        (x.Coefficients[p] + x.Coefficients[q]) *
                                                (y.Coefficients[p] + y.Coefficients[q])
                    }, 0, 2);
                }
        }
        MPI.Finalize();
    }
}
