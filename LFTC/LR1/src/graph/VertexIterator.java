package graph;

import java.util.Collection;
import java.util.Iterator;

/**
 * Created by andrapop on 2017-12-25.
 */
public class VertexIterator<T> implements Iterator<Vertex<T>> {
    Iterator<Edge<T>> iterator;

    VertexIterator(Collection<Edge<T>> neighbors) {
        iterator = neighbors.iterator();
    }

    @Override
    public boolean hasNext() {
        return iterator.hasNext();
    }

    @Override
    public Vertex<T> next() {
        return iterator.next().dest();
    }
}