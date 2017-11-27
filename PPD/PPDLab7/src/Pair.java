public class Pair {
    private int sum;
    private int fromLeft;

    public Pair(int sum, int fromLeft) {
        this.sum = sum;
        this.fromLeft = fromLeft;
    }

    public int getSum() {
        return sum;
    }

    public void setSum(int sum) {
        this.sum = sum;
    }

    public int getFromLeft() {
        return fromLeft;
    }

    public void setFromLeft(int fromLeft) {
        this.fromLeft = fromLeft;
    }

    @Override
    public String toString() {
        return "Pair{" +
                "sum=" + sum +
                ", fromLeft=" + fromLeft +
                '}';
    }
}
