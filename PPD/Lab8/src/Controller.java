import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collector;
import java.util.stream.IntStream;

/**
 * Created by andrapop on 2017-12-04.
 */
public class Controller {
    public void check(Digraph<Integer> graph, int v) {
        List permutation = new ArrayList<>();
        IntStream.range(0,v).forEach(n -> permutation.add(n));
        IntStream.range(0, 10000).forEach(n -> {
            Collections.shuffle(permutation);
            if (checkForHamCycle(permutation, graph)) {
                graph.hasHamCycle = true;
                return;
            }

        });
    }
    public Boolean checkForHamCycle(List<Integer> perm, Digraph<Integer> graph) {
            for(int i = 0; i < perm.size() - 1; i ++) {
                if(!graph.hasArc(perm.get(i), perm.get(i+1))) {
                    return false;
                }
            }
            if(!graph.hasArc(perm.get(perm.size() - 1), perm.get(0))) {
                return false;
            }
            return true;
    }


}
