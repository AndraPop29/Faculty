package graph;

import java.util.*;

/**
 * Created by andrapop on 2017-12-25.
 */
public class OrientedGraph<T> implements IGraph<T> {
    public HashMap<T, Vertex<T>> graph;

    public OrientedGraph() {
        graph = new HashMap<>();
    }

    public boolean contains(T vertex) {
        return graph.containsKey(vertex);
    }



    public boolean areAdjacent(T src, T dest) throws Exception {
        Vertex<T> srcVertex = graph.get(src);
        Vertex<T> destVertex = graph.get(dest);

        if (srcVertex == null || destVertex == null)
            throw new Exception();

        return srcVertex.hasNeighbor(destVertex);
    }

    public void addVertex(T vertex, Integer tag) {
        Vertex<T> vertexNode = new Vertex<>(vertex);
        vertexNode.tag = tag;
        graph.put(vertex, vertexNode);
    }

    public void removeVertex(T vertex) throws Exception {
        Vertex<T> vertexNode = graph.get(vertex);

        if (vertexNode == null)
            throw new Exception();

        Iterator<Vertex<T>> iterator = graph.values().iterator();
        while (iterator.hasNext()) {
            Vertex<T> possibleLink = iterator.next();
            possibleLink.removeEdgeTo(vertexNode);
        }

        graph.remove(vertex);
    }

    public void addEdge(T from, T to, String weight) throws Exception {
        Vertex<T> fromVertex = graph.get(from);
        Vertex<T> toVertex = graph.get(to);

        //System.out.println(fromVertex.toString());
        //System.out.println(toVertex);

        if (fromVertex == null || toVertex == null) {
            throw new Exception();
        }

        Edge<T> edge = new Edge<>(fromVertex, toVertex, weight);
        fromVertex.addEdge(edge);
    }

    public void removeEdge(T from, T to) throws Exception {
        Vertex<T> fromVertex = graph.get(from);
        Vertex<T> toVertex = graph.get(to);

        if (fromVertex == null || toVertex == null)
            throw new Exception();

        if (fromVertex.hasNeighbor(toVertex)) {
            fromVertex.removeEdgeTo(toVertex);
        }
    }

    public List<T> getNeighborsFor(T vertex) throws Exception {
        if (graph.get(vertex) == null)
            throw new Exception();

        return graph.get(vertex).getNeighbors();
    }

    public void depthSearch(T start) throws Exception {
        if (graph.get(start) == null)
            throw new Exception();

        Collection<T> visited = new HashSet<>();
        visited.add(start);

        Stack<T> stack = new Stack<>();
        stack.push(start);

        System.out.println(start);
        while (!stack.empty()) {
            T current = stack.peek();
            T neighbor = null;
            Iterator<T> iterator = getNeighborsFor(current).iterator();

            while (iterator.hasNext()) {
                neighbor = iterator.next();
                if (!visited.contains(neighbor))
                    break;
            }

            if (neighbor != null && !visited.contains(neighbor)) {
                visited.add(neighbor);
                System.out.println(neighbor);
                stack.push(neighbor);
            } else {
                stack.pop();
            }
        }
    }

    public void breathSearch(T start) throws Exception {
        if (graph.get(start) == null)
            throw new Exception();

        Collection<T> visited = new HashSet<>();
        visited.add(start);

        Queue<T> queue = new ArrayDeque<>();
        queue.add(start);

        System.out.println(start);
        while (!queue.isEmpty()) {
            T current = queue.remove();
            T neighbor= null;
            Iterator<T> iterator = getNeighborsFor(current).iterator();

            while (iterator.hasNext()) {
                neighbor = iterator.next();
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    System.out.println(neighbor);
                    queue.add(neighbor);
                }
            }
        }
    }

    @Override
    public String toString() {
        return "OrientedGraph{" +
                "graph=" + graph +
                '}';
    }

    public HashMap<T, Vertex<T>> getGraph() {
        return graph;
    }
}
