public class Main {
    public static void main(String[] argd) {
        ThreadBinaryTree tbt = new ThreadBinaryTree(8);
        for(Integer nr : tbt.getNumbers()) {
            System.out.print(nr);
            System.out.print(" ");
        }
        tbt.sumNBigNumbers(0, tbt.getNumbers().size(), tbt.getNumbers().size());
        System.out.println(tbt.getQ());
    }
}
