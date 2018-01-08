/**
 * Created by andrapop on 2017-12-24.
 */

public class Rule {
    public int tag;
    public String left;
    public String right;


    public Rule(String left, String right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        return "Rule{" +
                "left='" + left + '\'' +
                ", right='" + right + '\'' +
                '}';
    }
}
