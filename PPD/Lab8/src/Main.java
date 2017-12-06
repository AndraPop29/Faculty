import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.IntStream;

public class Main {
//    public static void checkForHamiltonianCycle(Digraph<Integer> graph, int v1, int v2, Integer noThreads) {
//        if(noThreads == 1) {
//            if(graph.hasArc(v1, v2)) {
//                graph.c ++;
//            }
//        } else {
//            int mid = (v1 + v2) / 2;
//            Thread t1 = new Thread(() -> checkForHamiltonianCycle(graph, v1, mid, noThreads/2));
//            Thread t2 = new Thread(() -> checkForHamiltonianCycle(graph, mid, v2, noThreads - noThreads/2));
//            t1.start();
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

    public static void main(String[] args) {
        Digraph<Integer> graph = new Digraph<Integer>();
        System.out.println("Enter the number of vertices: ");

        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();

        int[][] matrix = graph.generateRandomAdjMatrix(v);
        for(int i = 0; i < v; i ++) {
            for(int j = 0; j < v; j++) {
                if(matrix[i][j] == 1) {
                    graph.add(i,j);
                }
            }
        }
        Controller controller = new Controller();
        List<Thread> threads = new ArrayList<>();
        graph.hasHamCycle = false;
        IntStream.range(0,10).forEach(n -> threads.add(new Thread(() -> controller.check(graph, v))));
        threads.forEach(n -> n.start());
        threads.forEach(n -> {
            try {
                n.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
//        for(int i = 0; i < e; i++) {
//            graph.add( ThreadLocalRandom.current().nextInt(0, v),  ThreadLocalRandom.current().nextInt(0, v));
//        }
//        graph.add(0, 1);
//        graph.add(0, 2);
//        graph.add(0, 3);
//        graph.add(1, 2);
//        graph.add(1, 3);
//        graph.add(2, 3);
//        graph.add(2, 4);
//        graph.add(3, 4);
//        graph.add(4, 5);
//        graph.add(5, 6);
//        graph.add(6, 0);
        System.out.println(graph.toString());
        if(graph.hasHamCycle) {
            System.out.println("it has a hamiltonian cycle");
        } else {
            System.out.println("it doesn't have a hamiltonian cycle");
        }
//        Integer noThreads = 6;
        //checkForHamiltonianCycle(graph, 0, 6, noThreads);
//        if (graph.hasArc(6,0) && graph.c == 6) {
//            System.out.println("There is a hamiltonian cycle");
//        } else {
//            System.out.println("There is NOT a hamiltonian cycle");
//        }

    }
}
