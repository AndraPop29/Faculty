import java.io.InvalidObjectException;
import java.util.Arrays;
import java.util.stream.IntStream;

/**
 * Created by andrapop on 2017-11-20.
 */
public class PolyMultiplication {
    public PolyMultiplication()
    {

    }

    public static Polynomial Multiply(Polynomial a, Polynomial b) throws InvalidObjectException {
        int[] coefficients = new int[a._degree + b._degree + 1];

        for (int i = 0; i <= a._degree; ++i)
            for (int j = 0; j <= b._degree; ++j)
                coefficients[i + j] += a._coefficients[i] * b._coefficients[j];

        return new Polynomial(coefficients);
    }


    public static Polynomial MultiplyParallel(Polynomial a, Polynomial b) throws InvalidObjectException {

        int[] coefficients = new int[a._degree + b._degree + 1];

        IntStream.range(0, a._coefficients.length).parallel().forEach(i ->
                IntStream.range(0, b._coefficients.length).parallel().forEach(j ->
                coefficients[i + j] += a._coefficients[i] * b._coefficients[j]));


        return new Polynomial(coefficients);
    }

    public static Polynomial MultiplyKaratsuba(Polynomial x, Polynomial y) throws InvalidObjectException {
        if (x._degree != y._degree)
            throw new InvalidObjectException("Only works for polynomials of same degree!");

        int d = Math.min(x._degree, y._degree);
        int n = d + 1;

        int[] di = new int[n];
        int[][] dpq = new int[n][n];

        for (int i = 0; i <= n - 1; ++i)
            di[i] = x._coefficients[i] * y._coefficients[i];

        for (int i = 0; i <= 2 * n - 3; ++i)
            for (int p = 0; p <= i; ++p)
            {
                int q = i - p;
                if (p < n && q < n && q > p)
                    dpq[p][q] = (x._coefficients[p] + x._coefficients[q]) * (y._coefficients[p] + y._coefficients[q]);
            }

        int[] result = new int[2 * n - 1];

        result[0] = di[0];
        result[2 * n - 2] = di[n - 1];
        for (int i = 1; i <= 2 * n - 3; ++i)
        {
            for (int p = 0; p <= i; ++p)
            {
                int q = i - p;
                if (p < n && q < n && q > p)
                    result[i] += dpq[p][q] - (di[p] + di[q]);
            }

            if (i % 2 == 0)
                result[i] += di[i / 2];
        }

        return new Polynomial(result);
    }

    public static Polynomial KaratsubaParallel(Polynomial x, Polynomial y) throws InvalidObjectException {

        int n = x._degree + 1;


        int[] d = new int[n];
        int[][] d2 = new int[n][n];

        IntStream.range(0, n).parallel().forEach(i ->  d[i] = x._coefficients[i] * y._coefficients[i]);

        IntStream.range(0, 2*n-2).parallel().forEach(i ->
                IntStream.range(0, i+1).parallel().forEach(p -> {
                            int q = i - p;
                            if (p < n && q < n && q > p)
                                d2[p][q] = (x._coefficients[p] + x._coefficients[q]) * (y._coefficients[p] + y._coefficients[q]);
                        }
                )

            );

        int[] result = new int[2 * n - 1];

        result[0] = d[0];
        result[2 * n - 2] = d[n - 1];

        IntStream.range(1,2*n-2).parallel().forEach(i -> {
                    IntStream.range(0, i+1).forEach(p -> {
                                int q = i - p;
                                if (p < n && q < n && q > p)
                                    result[i] += d2[p][q] - (d[p] + d[q]);
                            }
                    );
                    if (i % 2 == 0)
                        result[i] += d[i / 2];
                }
        );

        return new Polynomial(result);

    }


}
