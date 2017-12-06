import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.*;
import java.util.stream.IntStream;

public class ThreadBinaryTree {
   // private int n;
    private List<List<Integer>> numbers;
    private BlockingQueue<Integer> q;
    ThreadBinaryTree(List numbers) {
      //  this.n = n;
        this.numbers = numbers;
        //this.q = new LinkedList<Integer>();
      //  generateRandNumberList();
    }
//    public void generateRandNumberList() {
//        IntStream.range(0, n).forEach(n -> numbers.add(ThreadLocalRandom.current().nextInt(10000, 1000000)));
//    }
//    public void sumNBigNumbers(int begin, int end, int nrThreads) {
//        if(nrThreads == 1) {
//            int val = this.numbers.get(begin);
//            while(val > 0) {
//                q.add(val % 10);
//                val = val / 10;
//                try {
//                    Thread.sleep(1000);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//            }
//        } else {
//            int mid = (begin + end) / 2;
//            Thread t1 = new Thread(() -> sumNBigNumbers(begin, mid, nrThreads /2));
//            t1.start();
//            Thread t2 = new Thread(() -> sumNBigNumbers(mid, end, nrThreads - nrThreads /2));
//            t2.start();
//
//            try {
//                t1.join();
//                t2.join();
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//    }

    public BlockingQueue sumNBigNumbers(int i1, int i2, BlockingQueue<Integer> res) {
        if (i1 == i2) {
            for(int c : this.numbers.get(i1)) {
                res.add(c);
            }
            return res;
        }
        if (i1 == i2 - 1) {
            int carry = 0;
            int len1 = numbers.get(i1).size();
            int len2 = numbers.get(i1).size();
            int minLength = Math.min(len1, len2);
            for (int i = 0; i < minLength; i ++) {
                int tmp = numbers.get(i1).get(i) + numbers.get(i2).get(i) + carry;
                res.add(tmp % 10);
                carry = tmp / 10;
            }
            for (int i = 0; i < len1 - len2; i ++) {
                int tmp = numbers.get(i1).get(i + len2) + numbers.get(i2).get(i) + carry;
                res.add(tmp % 10);
                carry = tmp / 10;
            }
            for (int i = 0; i < len2 - len1; i ++) {
                int tmp = numbers.get(i1).get(i + len2) + numbers.get(i2).get(i) + carry;
                res.add(tmp % 10);
                carry = tmp / 10;
            }
            if(carry == 1) {
                res.add(carry);
            }
            return res;
        }
        int mid = (i1 + i2) / 2;
        final BlockingQueue<Integer> q1 = new LinkedBlockingQueue();
        final BlockingQueue<Integer> q2 = new LinkedBlockingQueue();
        ExecutorService executorService = Executors.newFixedThreadPool(2);
        Future<BlockingQueue> t1 = executorService.submit(() -> sumNBigNumbers(i1, mid, q1));
        Future<BlockingQueue> t2 = executorService.submit(() -> sumNBigNumbers(mid + 1, i2, q2));
        //Thread t1 = new Thread(() -> sumNBigNumbers(i1, mid, queue1));
        //Thread t2 = new Thread(() -> sumNBigNumbers(mid + 1, i2, queue2));
        //t1.start();
        //t2.start();
//        try {
//            t1.join();
//            t2.join();
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
        BlockingQueue<Integer> queue1 = new LinkedBlockingQueue();
        BlockingQueue<Integer> queue2 = new LinkedBlockingQueue();
        executorService.shutdown();

        try {
            executorService.awaitTermination(60000, TimeUnit.NANOSECONDS);

            queue1 = t1.get();
            queue2 = t2.get();
            System.out.println(queue1);

            System.out.println(queue2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }


        int carry = 0;
        while(true) {
            Integer c1 = queue1.poll();
            Integer c2 = queue2.poll();

            if (c1 == null) {
                while (c2 != null) {
                    int tmp = c2 + carry;
                    res.add(tmp % 10);
                    carry = tmp / 10;
                    c2 = queue2.poll();

                }
//                try {
//                    t1.join();
//                    t2.join();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
                if (carry == 1) {
                    res.add(carry);
                }
                return res;
            }
            else if (c2 == null) {
                while (c1 != null) {
                    int tmp = c1 + carry;
                    res.add(tmp % 10);
                    carry = tmp / 10;
                    c1 = queue1.poll();

                }
//                try {
//                    t1.join();
//                    t2.join();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
                if (carry == 1) {
                    res.add(carry);
                }
                return res;
            }
            else {
                int tmp = c1 + c2 + carry;
                res.add(tmp % 10);
                carry = tmp / 10;
            }

        }
    }


    public Queue<Integer> getQ() {
        System.out.println(q);
        return q;
    }

}
