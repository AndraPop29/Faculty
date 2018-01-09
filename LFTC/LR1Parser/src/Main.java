/**
 * Created by andrapop on 2017-12-24.
 */
public class Main {
    public static void main(String[] args) {
        Parser parser = new Parser("res/contextFreeGrammar2.in");
        parser.generateParsingAutomatum();
    }
}
