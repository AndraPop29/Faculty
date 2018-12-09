package graph;

import java.util.Collection;

/**
 * Created by andrapop on 2017-12-25.
 */
public interface IGraph<T> {
    boolean contains(T item);
    void addVertex(T vertex, Integer tag);
    boolean areAdjacent(T a, T b) throws Exception;
    void removeVertex(T vertex) throws Exception;
    void addEdge(T from, T to, String weight) throws Exception;
    void removeEdge(T from, T to) throws Exception;
    Collection<T> getNeighborsFor(T vertex) throws Exception;
    void depthSearch(T start) throws Exception;
    void breathSearch(T start) throws Exception;
}
