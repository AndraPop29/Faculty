import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println("n = ");
        int n = reader.nextInt(); // number of threads to give to the thread pool
        NumberSum nrSum = new NumberSum(n);
        nrSum.addNumbers();
        System.out.println("NUMBERS");
        for(Integer nr : nrSum.getNumbers()) {
            System.out.println(nr);
        }
        System.out.println("SUMS");
        for(Integer nr : nrSum.getSums()) {
            System.out.println(nr);
        }

    }
}
