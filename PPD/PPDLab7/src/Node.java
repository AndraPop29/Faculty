
public class Node {
    private Pair key;
    private Node left;
    private Node right;

    Node (Pair key) {
        this.key = key;
        right = null;
        left = null;
    }

    public void setKey(Pair key) {
        this.key = key;
    }

    public Pair getKey() {
        return key;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getLeft() {
        return left;
    }

    public void setRight(Node right ) {
        this.right = right;
    }

    public Node getRight() {
        return right;
    }
}
