import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println("n = ");
        int n = reader.nextInt(); // should be a multiple of 2^n
        NumberSum nrSum = new NumberSum(n);
        nrSum.buildThreadBinaryTree();
        System.out.println("NUMBERS");
        for(Integer nr : nrSum.getNumbers()) {
            System.out.println(nr);
        }
        System.out.println("SUMS");
        for(Pair sum : nrSum.getSums()) {
            System.out.println(sum.getFromLeft());
        }

    }
}
