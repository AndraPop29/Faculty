public class Main {
    public static void main(String[] args) {
        Digraph<Integer> graph = new Digraph<Integer>();
        graph.add(0, 1);
        graph.add(0, 2);
        graph.add(0, 3);
        graph.add(1, 2);
        graph.add(1, 3);
        graph.add(2, 3);
        graph.add(2, 4);
        graph.add(4, 5);
        graph.add(5, 6);
        System.out.println("The current graph: " + graph);
        System.out.println("In-degrees: " + graph.inDegree());
        System.out.println("Out-degrees: " + graph.outDegree());
    }
}
