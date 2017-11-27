/*
1. Given a sequence of n numbers, compute the sums of the first k numbers, for each k between 1 and n. Parallelize the computations,
        to optimize for low latency on a large number of processors. Use at most 2*n additions, but no more than 2*log(n) additions on each computation path from inputs to an output.
        Example: if the input sequence is 1 5 2 4, then the output should be 1 6 8 12.
        */


import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;
import java.util.stream.IntStream;


public class NumberSum {
    private int n;
    private List<Integer> numbers;
    private List<Pair> sums;
    public NumberSum(int n) {
        numbers = new ArrayList<>();
        numbers.add(5);
        numbers.add(3);
        numbers.add(-6);
        numbers.add(2);
        numbers.add(7);
        numbers.add(10);
        numbers.add(-2);
        numbers.add(8);

        sums = new ArrayList<>();
    }

    public void buildThreadBinaryTree() {
        // PASS 1
        ExecutorService service = Executors.newFixedThreadPool(20);
        List<Future<Runnable>> futures = new ArrayList<Future<Runnable>>();
        for(int i = 0 ; i<numbers.size(); i+=2) {
            final int j = i;
            futures.add(service.submit(new Thread(new Runnable(() {
             //   @Override
                public void run() {
                    sums.add(new Pair(numbers.get(j), 0));
                }
            }));
           // futures.add(service.submit(new Thread(() -> sums.add(new Pair(numbers.get(j+1) + numbers.get(j), 0)))));
        }
        for (Future<Runnable> f : futures)
        {
            try {
                f.get();
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (ExecutionException e) {
                e.printStackTrace();
            }
        }
        int i = 0;
        int k = 4;
        while(i<numbers.size()) {
            int sum = sums.get(i+k-1).getSum() + sums.get(i+k-(k/2)-1).getSum();
            sums.set(i+k-1, new Pair(sum, 0));
            i += k;
            if(i >= numbers.size() && k < numbers.size()) {
                i = 0;
                k = k * 2;
            }

        }

        //PASS 2
        i = 0;
        k = sums.size();
        sums.get(sums.size() - 1).setFromLeft(0);
        while(i < numbers.size()) {
            sums.set(i+k-(k/2)-1, new Pair(sums.get(i+k-(k/2)-1).getSum(), sums.get(i+k-1).getFromLeft())); //left child
            int fromLeft = sums.get(i+k-1).getFromLeft() + sums.get(i+k-(k/2)-1).getSum();
            sums.set(i+k-1, new Pair(sums.get(i+k-1).getSum(), fromLeft)); // right child
            i += k;
            if(i >= numbers.size() && k > 2) {
                i = 0;
                k = k / 2;
            }
        }

    }

    public void addNumbers() {

    }

    public int getN() {
        return n;
    }

    public void setN(int n) {
        this.n = n;
    }

    public List<Integer> getNumbers() {
        return numbers;
    }

    public void setNumbers(List numbers) {
        this.numbers = numbers;
    }

    public List<Pair> getSums() {
        return sums;
    }
}
