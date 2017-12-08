import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println("n = ");
        int n = reader.nextInt();
        NumberSum nrSum = new NumberSum(n);
        nrSum.buildThreadBinaryTree();
        System.out.println("NUMBERS");
        for(Integer nr : nrSum.getNumbers()) {
            System.out.print(nr+" ");
        }
        System.out.println();
        System.out.println("SUMS");
        for(int i = 1; i < nrSum.getSums().size(); i++) {
            System.out.print(nrSum.getSums().get(i).getFromLeft()+" ");
        }
        System.out.println(nrSum.getSums().get(nrSum.getSums().size() - 1).getSum());

    }
}
