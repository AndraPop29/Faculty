import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] argd) {
        String[] inputNumbers = {"18300185877878983000", "94111802487705630000", "43506089492427090", "18980939942703710000", "43244811007774260000", "43608238829313820000", "54051738540040616"};
        //int[][] numbers = new int[inputNumbers.length][];
        List<List> numbers = new ArrayList<>();
        IntStream.range(0, inputNumbers.length).forEach(i -> {
            int nrLen = inputNumbers[i].length();
            ArrayList<Integer> singleList = new ArrayList<>();
            for(int j = nrLen - 1; j > 0; j --) {
                singleList.add(Character.getNumericValue(inputNumbers[i].charAt(j)));
               // numbers.[nrLen - j - 1] = Character.getNumericValue(inputNumbers[i].charAt(j));
            }
            System.out.println(singleList);
            numbers.add(singleList);
        });
        System.out.println("-------------------------");
        BlockingQueue<Integer> result = new LinkedBlockingDeque<>();
        ThreadBinaryTree tbt = new ThreadBinaryTree(numbers);
        result = tbt.sumNBigNumbers(0, numbers.size() - 1, result);
        List finalResult = new ArrayList<>();
        System.out.println(result);
        while (!result.isEmpty()) {
            finalResult.add(result.poll());
        }
        for(int i = result.size() - 1; i >= 0; i --) {
            System.out.println(finalResult.get(i));
        }
    }
}
