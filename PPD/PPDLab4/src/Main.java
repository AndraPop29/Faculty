import javax.jws.soap.SOAPBinding;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by andrapop on 2017-11-03.
 */
public class Main {
    public static int m;
    static int[][] a;
    static int[][] b;
    static int[][] c;
    public static int[][] result;
    public static int[][] finalResult;
    static int[] resultVector;
    static Lock lock;

    public static void multiplyFirst2Matrices(int i, int j) {
        for (int k = 0; k < a[0].length; k++) {
            result[i][j] += a[i][k] * b[k][j];
        }
       // System.out.println("Id of thread: "+ Thread.currentThread().getId()+", line "+i);
        lock.lock();
        resultVector[i]++;
        lock.unlock();
    }

    public static void multiplyLine(int index) {
        for (int j = 0; j < c[0].length; j++) {
            for (int k = 0; k < result[0].length; k++) {
                finalResult[index][j] += result[index][k] * c[k][j];
            }
        }
    }

    public static void multiplyPartialResultWithLastMatrix(int m) {
        ExecutorService executor = Executors.newFixedThreadPool(m);
        int lines = m;
        while(lines > 0) {
            for(int i = 0; i < resultVector.length; i++) {
                if (resultVector[i] == m) {
                    final int in = i;
                    executor.execute(new Thread(() -> multiplyLine(in)));
                    lines--;
                    resultVector[i] = 0;
                }
            }
        }
        executor.shutdown();
        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    public static void ThreadPool(int n) {
        ExecutorService executor = Executors.newFixedThreadPool(n);
        executor.execute(new Thread(() ->  multiplyPartialResultWithLastMatrix(m)));
        for(int i=0; i<m; i++) {
            for (int j = 0; j < b[0].length; j++) {
                final int fi = i;
                final int fj = j;
                executor.execute(new Thread(() -> multiplyFirst2Matrices(fi,fj)));
            }
        }
        executor.shutdown();
        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println("Enter a number of threads: ");
        int n = reader.nextInt(); // number of threads to give to the thread pool
        System.out.println("Number of lines for first matrix: ");
        m = reader.nextInt();
        System.out.println("Number of columns for first matrix: ");
        int k = reader.nextInt();

        a = new int[m][k];
        b = new int[k][m];
        c = new int[m][m];

        result = new int[m][m];
        finalResult = new int[m][m];
        resultVector = new int[m];
        lock = new ReentrantLock();


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                a[i][j] = (int) (Math.random() * 10);
                b[j][i] = (int) (Math.random() * 10);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = (int) (Math.random() * 10);
                result[i][j] = 0;
            }
        }

        long startTime = System.nanoTime();
        ThreadPool(n);
        long endTime = System.nanoTime();
        long totalDuration = (endTime - startTime);
        System.out.println("The duration in miliseconds:");
        System.out.println(totalDuration / 1000000000.0);
        reader.close();

//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < m; j++) {
//
//                System.out.print(finalResult[i][j] + " ");
//            }
//            System.out.println();
//        }
    }
}
