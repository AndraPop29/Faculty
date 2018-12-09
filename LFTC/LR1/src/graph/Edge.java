package graph;

/**
 * Created by andrapop on 2017-12-25.
 */
public class Edge<T> {
    public Vertex<T> from;
    public Vertex<T> to;
    public String weight;

    Edge(Vertex<T> from, Vertex<T> to, String weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }

    Vertex<T> dest() {
        return to;
    }

    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Edge<T> other = (Edge<T>) obj;
        if (from == null) {
            if (other.from != null)
                return false;
        } else if (!from.equals(other.from))
            return false;
        if (to == null) {
            if (other.to != null)
                return false;
        } else if (!to.equals(other.to))
            return false;
        if (weight != other.weight)
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Edge{" +
                "from=" + from +
                ", to=" + to +
                ", weight='" + weight + '\'' +
                '}';
    }

    @Override
    public int hashCode() {
        int result = from.hashCode();
        result = 31 * result + to.hashCode();
        result = 31 * result + weight.hashCode();
        return result;
    }
}
