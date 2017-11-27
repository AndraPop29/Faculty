/*
1. Given a sequence of n numbers, compute the sums of the first k numbers, for each k between 1 and n. Parallelize the computations,
        to optimize for low latency on a large number of processors. Use at most 2*n additions, but no more than 2*log(n) additions on each computation path from inputs to an output.
        Example: if the input sequence is 1 5 2 4, then the output should be 1 6 8 12.
        */


import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.IntStream;


public class NumberSum {
    private int n;
    private List<Integer> numbers;
    private List<Pair> sums;
    public NumberSum(int n) {
        numbers = new ArrayList<>();
//        numbers.add(5);
//        numbers.add(3);
//        numbers.add(-6);
//        numbers.add(2);
//        numbers.add(7);
//        numbers.add(10);
//        numbers.add(-2);
//        numbers.add(8);
        sums = new ArrayList<>();
        IntStream.range(0,n).forEach(nr -> numbers.add(ThreadLocalRandom.current().nextInt(1, 11)));
    }

    public void buildThreadBinaryTree() {
        // PASS 1
        List<Thread> threads = new ArrayList<>();
        for(int i = 0 ; i<numbers.size(); i+=2) {
            final int j = i;
            threads.add(new Thread(() -> sums.add(new Pair(numbers.get(j), 0))));
            threads.get(threads.size() -1).start();
            threads.add(new Thread(() -> sums.add(new Pair(numbers.get(j+1) + numbers.get(j), 0))));
            threads.get(threads.size() -1).start();
        }
        for(Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        int i = 0;
        int k = 4;
        while(i<numbers.size()) {
            final int i1 = i;
            final int k1 = k;
            threads.add(new Thread(() -> {
                int sum = sums.get(i1+k1-1).getSum() + sums.get(i1+k1-(k1/2)-1).getSum();
                sums.set(i1+k1-1, new Pair(sum, 0));
            }));
            threads.get(threads.size()-1).start();
            i += k;
            if(i >= numbers.size() && k < numbers.size()) { // move up a level in tree
                for(Thread t : threads) {
                    try {
                        t.join();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                i = 0;
                k = k * 2;
            }

        }

        //PASS 2
        i = 0;
        k = sums.size();
        sums.get(sums.size() - 1).setFromLeft(0);
        while(i < numbers.size()) {
            final int i1 = i;
            final int k1 = k;
            threads.add(new Thread(() -> sums.set(i1+k1-(k1/2)-1, new Pair(sums.get(i1+k1-(k1/2)-1).getSum(), sums.get(i1+k1-1).getFromLeft())))); //left child
            threads.get(threads.size()-1).start();
            threads.add(new Thread(() -> {
                int fromLeft = sums.get(i1+k1-1).getFromLeft() + sums.get(i1+k1-(k1/2)-1).getSum();
                sums.set(i1+k1-1, new Pair(sums.get(i1+k1-1).getSum(), fromLeft)); // right child
            }));
            threads.get(threads.size()-1).start();
            i += k;
            if(i >= numbers.size() && k > 2) { // move down a level in tree
                for(Thread t : threads) {
                    try {
                        t.join();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                i = 0;
                k = k / 2;
            }
        }

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
