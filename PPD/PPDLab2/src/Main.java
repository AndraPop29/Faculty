import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.*;

/**
 * Created by andrapop on 2017-10-09.
 */

/*

    Write a program for multiplying 2 matrices (m,k) * (k,m) using n threads (ny splitting the the tasks as evenly as possible)
    Example:
    m = 14 |
    k = 3  | => 3 threads: 1st: first 5 lines, 2nd: following 5 lines, 3rd: following 4 lines
 */
public class Main
{
    public static int m;
    public static int k;
    static int[][] a;
    static int[][] b;

    public static void readFromFile() throws FileNotFoundException {
        try {
            Scanner input = new Scanner(new File("/Users/andrapop/Faculty/PPD/src/array.txt"));

            while (input.hasNextLine()) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < k; j++) {
                        try{//    System.out.println("number is ");
                            a[i][j] = input.nextInt();

                        }
                        catch (java.util.NoSuchElementException e) {
                            // e.printStackTrace();
                        }
                    }
                }
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < m; j++) {
                        try{//    System.out.println("number is ");
                            b[i][j] = input.nextInt();

                        }
                        catch (java.util.NoSuchElementException e) {
                            // e.printStackTrace();
                        }
                    }
                }

            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    public static int[][] result;

    public static Void multiplyMatrices(int x, int y) { // multiplies only the lines in [x,y] from the first matrix with the second
        for(int i = x ; i < y ; i ++ )
            for(int j = 0 ; j < b[0].length ; j ++) {
                //System.out.println(b[0].length);
                for (int k = 0; k < a[0].length; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        return null;
    }

    public static long totalDuration;

    public static void simpleThreads(int n, int rest, int var, int nr) {
        Thread threads [] = new Thread[n];
        int j = 0; // start of first interval
        while(rest > 0) {
            final int c1 = j;
            threads[var] = new Thread(() -> multiplyMatrices(c1, c1 + nr + 1));
            threads[var].start();
            var++;
            rest --;
            n--;
            j = j + nr + 1;
        }

        for(int i = 0 ; i < n ; i ++) {
            final int c2 = j;
            threads[var] = new Thread(() -> multiplyMatrices(c2, c2 + nr));
            threads[var].start();
            j = j + nr ;
        }
        for(Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public static void ThreadPool(int n, int rest, int var, int nr) {
        ExecutorService executor = Executors.newFixedThreadPool(n);
        int j = 0; // start of first interval
        while(rest > 0) {
            final int c1 = j;
            executor.execute(new Thread(() -> multiplyMatrices(c1, c1 + nr + 1)));
            var++;
            rest --;
            n--;
            j = j + nr + 1;
        }

        for(int i = 0 ; i < n ; i ++) {
            final int c2 = j;
            executor.execute(new Thread(() -> multiplyMatrices(c2, c2 + nr)));
            j = j + nr ;
        }

        executor.shutdown();
       // while(!executor.isTerminated()) {}
        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    public static void FutureTask(int n, int rest, int var, int nr) {
        ExecutorService executor = Executors.newFixedThreadPool(n);
        List<Future> futureList = new ArrayList<>();
        int j = 0; // start of first interval
        while(rest > 0) {
            final int c1 = j;
            futureList.add(executor.submit(new Thread(() -> multiplyMatrices(c1, c1 + nr + 1))));
            var++;
            rest --;
            n--;
            j = j + nr + 1;
        }

        for(int i = 0 ; i < n ; i ++) {
            final int c2 = j;
            futureList.add(executor.submit(new Thread(() -> multiplyMatrices(c2, c2 + nr))));
            j = j + nr ;
        }

        executor.shutdown();

        for(Future f: futureList) {
            try {
                f.get();
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (ExecutionException e) {
                e.printStackTrace();
            }
        }
    }
    public static void main(String []args) throws FileNotFoundException {
        Scanner reader = new Scanner(System.in);
        System.out.println("Enter a number of threads: ");
        int n = reader.nextInt(); // number of threads
        System.out.println("Number of lines for first matrix: ");
        int m = reader.nextInt();
        System.out.println("Number of columns for first matrix: ");

        int k = reader.nextInt();
        a = new int[m][k];
        b = new int[k][m];
        result = new int[m][m];
        totalDuration = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<k; j++) {
                a[i][j] = (int) (Math.random()*10);
                b[j][i] = (int) (Math.random()*10);
            }
        }
        if(n > m) {
            n = m;
        }

        if(n < 1) {
            n = 1;
        }
        final int nr = m/n; // nr of elements(lines of matrix) in intervals if equal division is possible
        int rest = m % n; //nr of elements to be redistributed(if equal division is not possible


        int var = 0;
        long startTime = System.nanoTime();
        //simpleThreads(n, rest, var, nr);
        FutureTask(n, rest, var, nr);
        //ThreadPool(n, rest, var, nr);
        long endTime = System.nanoTime();
        long totalDuration = (endTime - startTime);
        System.out.println("The duration in miliseconds:");
        System.out.println(totalDuration/1000000000.0);
        reader.close();

//        System.out.println("RESULT:");
//        for (int i = 0; i < m; i++) {
//            for (int g = 0; g < m; g++) {
//                System.out.print(result[i][g]+" ");
//            }
//            System.out.println();
//
//        }





    }

}
