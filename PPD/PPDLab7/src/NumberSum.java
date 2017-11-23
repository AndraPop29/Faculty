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
    private List<Integer> sums;
    public NumberSum(int n) {
        numbers = new ArrayList<>();
        sums = new ArrayList<>();
        IntStream.range(0, n).forEach(nr -> numbers.add(ThreadLocalRandom.current().nextInt(1, 11)));
    }

    public void addNumbers() {
        sums.add(numbers.get(0));
        IntStream.range(1, numbers.size()).parallel().forEach(i -> sums.add(sums.get(sums.size() - 1) + numbers.get(i)));
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

    public List<Integer> getSums() {
        return sums;
    }
}
