import javax.print.DocFlavor;
import java.io.InvalidObjectException;
import java.util.Arrays;
import java.util.Random;

/**
 * Created by andrapop on 2017-11-20.
 */
public class Polynomial {
    public static Random R = new Random();

    public int _degree;

    public int[] _coefficients;

    public Polynomial(int[] coefficients) throws InvalidObjectException {
        if ((coefficients == null) || (coefficients.length == 0)) {
            throw new InvalidObjectException("Invalid coefficients specification!");
        }

        _degree = coefficients.length - 1;
        _coefficients = coefficients;
    }

    // Generates a random polynomial of a given degree.
    public static Polynomial RandomPolynomial(int degree) throws InvalidObjectException {
        if (degree < 0)
            throw new InvalidObjectException("Invalid degree specification!");

        int[] coefficients = new int[degree + 1];

        for (int i = 0; i <= degree; ++i)
            coefficients[i] = R.nextInt(10);

        return new Polynomial(coefficients);
    }

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i <= _degree; ++i)
            sb.append(String.format("%s%d*X^%d", _coefficients[i] >= 0 ? "+" : "", _coefficients[i], i));

        return sb.toString();
    }
}
