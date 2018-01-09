import javax.print.DocFlavor;
import java.util.List;
import java.util.Set;

/**
 * Created by andrapop on 2017-12-24.
 */
public class FirstFollow {

    private Set<Character> first;
    private Set<Character> follow;


    public FirstFollow(Set<Character> first, Set<Character> follow) {
        this.first = first;
        this.follow = follow;
    }

    public FirstFollow() {
    }

    public Set<Character> getFirst() {
        return first;
    }

    public void setFirst(Set<Character> first) {
        this.first = first;
    }

    public Set<Character> getFollow() {
        return follow;
    }

    public void setFollow(Set<Character> follow) {
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
