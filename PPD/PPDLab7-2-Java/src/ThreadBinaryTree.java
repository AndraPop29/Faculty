import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.IntStream;

public class ThreadBinaryTree {
    private int n;
    private List<Integer> numbers;
    private Queue<Integer> q;
    ThreadBinaryTree(int n) {
        this.n = n;
        this.numbers = new ArrayList<>();
        this.q = new LinkedList<Integer>();
        generateRandNumberList();
    }
    public void generateRandNumberList() {
        IntStream.range(0, n).forEach(n -> numbers.add(ThreadLocalRandom.current().nextInt(10000, 1000000)));
    }
    public void sumNBigNumbers(int begin, int end, int nrThreads) {
        if(nrThreads == 1) {
            int val = this.numbers.get(begin);
            while(val > 0) {
                q.add(val % 10);
                val = val / 10;
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        } else {
            int mid = (begin + end) / 2;
            Thread t1 = new Thread(() -> sumNBigNumbers(begin, mid, nrThreads /2));
            t1.start();
            Thread t2 = new Thread(() -> sumNBigNumbers(mid, end, nrThreads - nrThreads /2));
            t2.start();

            try {
                t1.join();
                t2.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public List<Integer> getNumbers() {
        return numbers;
    }

    public void setNumbers(List<Integer> numbers) {
        this.numbers = numbers;
    }

    public Queue<Integer> getQ() {
        System.out.println(q);
        return q;
    }

    public void setQ(Queue<Integer> q) {
        this.q = q;
    }
}
