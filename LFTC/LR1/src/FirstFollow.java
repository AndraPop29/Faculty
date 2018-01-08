import javax.print.DocFlavor;
import java.util.List;

/**
 * Created by andrapop on 2017-12-24.
 */
public class FirstFollow {

    private List<Character> first;
    private List<Character> follow;


    public FirstFollow(List<Character> first, List<Character> follow) {
        this.first = first;
        this.follow = follow;
    }

    public FirstFollow() {
    }

    public List<Character> getFirst() {
        return first;
    }

    public void setFirst(List<Character> first) {
        this.first = first;
    }

    public List<Character> getFollow() {
        return follow;
    }

    public void setFollow(List<Character> follow) {
        this.follow = follow;
    }

    @Override
    public String toString() {
        return "FirstFollow{" +
                "first=" + first +
                ", follow=" + follow +
                '}';
    }
}
