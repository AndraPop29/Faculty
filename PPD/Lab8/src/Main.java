import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

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

        System.out.println(graph.toString());
        if(graph.hasHamCycle) {
            System.out.println("it has a hamiltonian cycle");
        } else {
            System.out.println("it doesn't have a hamiltonian cycle");
        }


    }
}
