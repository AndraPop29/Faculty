import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * Created by andrapop on 2017-12-25.
 */
public class Production {
    public String nonterminal;
    public List<String> stack;
    public List lookahead;
    public Integer dotPosition;

    public Production(String nonterminal, List<String> stack, List lookahead) {
        dotPosition = 0;
        this.nonterminal = nonterminal;
        this.stack = stack;
        this.lookahead = lookahead;
    }

    public Production(String nonterminal, List<String> stack, List lookahead, Integer dotPos) {
        this.dotPosition = dotPos;
        this.nonterminal = nonterminal;
        this.stack = stack;
        this.lookahead = lookahead;
    }

    public Production() {
        dotPosition = 0;
        nonterminal = "";
        stack = new ArrayList<>();
        lookahead = new ArrayList();
    }


    @Override
    public String toString() {
        return "Production{" +
                "nonterminal='" + nonterminal + '\'' +
                ", stack=" + stack +
                ", lookahead=" + lookahead +
                ", dotPosition=" + dotPosition +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Production that = (Production) o;

        if (!nonterminal.equals(that.nonterminal)) return false;
        if (!stack.equals(that.stack)) return false;
        if (!lookahead.equals(that.lookahead)) return false;
        return dotPosition.equals(that.dotPosition);
    }

    @Override
    public int hashCode() {
        int result = nonterminal.hashCode();
        result = 31 * result + stack.hashCode();
        result = 31 * result + lookahead.hashCode();
        result = 31 * result + dotPosition.hashCode();
        return result;
    }
}
