/**
 * Created by andrapop on 2017-10-22.
 */
public class Main {
    public static void main(String []args){
        LexicalAnalyzer analizer = new LexicalAnalyzer();
        analizer.generateFSA();
        analizer.displayTransitions();
        analizer.generateTables("circle.txt");

    }
}
