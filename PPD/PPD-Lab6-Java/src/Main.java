import java.io.InvalidObjectException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by andrapop on 2017-11-20.
 */
public class Main {
    public static void main(String[] args) {
        Polynomial a = null;
        Polynomial b = null;
        long startTime = 0;
        long endTime = 0;
        long totalDuration = 0;
        try {
            a = Polynomial.RandomPolynomial(100);
            b = Polynomial.RandomPolynomial(100);
        } catch (InvalidObjectException e) {
            e.printStackTrace();
        }

        try {
            List list = new ArrayList();
            startTime = System.nanoTime();
            //PolyMultiplication.Multiply(a, b);
            //PolyMultiplication.MultiplyParallel(a, b);
            PolyMultiplication.MultiplyKaratsuba(a, b);
            //PolyMultiplication.KaratsubaParallel(a, b);
            endTime = System.nanoTime();
            totalDuration = (endTime - startTime);
            System.out.println("The duration in miliseconds:");
            System.out.println(totalDuration/1000000000.0);

        } catch (InvalidObjectException e) {
            e.printStackTrace();
        }
    }
}
