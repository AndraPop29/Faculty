import graph.OrientedGraph;

import javax.print.DocFlavor;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


/**
 * Created by andrapop on 2017-12-24.
 */
public class Parser {
    public HashMap<String, FirstFollow> firstFollowTable;
    public List<Rule> rules;
    public Set<String> nonterminals;
    public Integer counter;
    public HashMap<Integer, HashMap<String, String>> table;

    public Parser(String grammarFile) {
        firstFollowTable = new HashMap<>();
        rules = new ArrayList<>();
        nonterminals = new HashSet<>();
        counter = 0;
        table = new HashMap();
        loadFromFile(grammarFile);
    }

    public void loadFromFile(String file) {
        try(
                FileInputStream fin = new FileInputStream(file);
                BufferedReader reader = new BufferedReader(new InputStreamReader(fin))
        ) {
            String line = null;

            int numberOfRules = 0;

            // read number of states (first line)
            line = reader.readLine();
            numberOfRules = Integer.parseInt(line);

            // process states (next 'numberOfStates' lines)
            for (int i = 0; i < numberOfRules; i++) {
                line = reader.readLine();

                String[] tokens = line.split(":");

                if (tokens.length > 2) {
                    System.err.println("Invalid file format.");
                    return;
                }

                this.rules.add(new Rule(tokens[0], tokens[1]));
            }

        }
        catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }

    public static boolean isNumeric(String str)
    {
        return str.matches("-?\\d+(\\.\\d+)?");  //match a number with optional '-' and decimal.
    }

    public Set getFirst(String left) {
        Set<Character> list = new HashSet<>();
        rules.stream().forEach(r -> {
            if(r.left.equals(left)) {
                if (!nonterminals.contains(String.valueOf(r.right.charAt(0)))) {
                    list.add(r.right.charAt(0));
                }
                else {
                    list.addAll(firstFollowTable.get(String.valueOf(r.right.charAt(0))).getFirst());
                }
            }
        });
//        List<Character> list1 = new ArrayList<>();
//        list1.addAll(list);
        return list;
    }

    public Set getFollow(String left) {
        Set<Character> list = new HashSet<>();
        int index = 0;
        List<Rule> rules2 = new ArrayList<>();
        for(int i = rules.size() - 1; i >= 0; i --) {
            rules2.add(rules.get(i));
        }
        for(Rule r : rules) {
            index ++;
//            if (r.left.equals(left) && index == 0) { // rule #1: if start symbol, add $
//                list.add('$');
//            }
            int listSize = list.size();
            if (r.right.contains(left)) {
                for (int i = 0; i < r.right.length(); i++) {
                    if (String.valueOf(r.right.charAt(i)).equals(left) && !r.left.equals(left)) {
                       // if (i == 1) {
                            if (i < r.right.length() - 1) {

                                if (!(nonterminals.contains(String.valueOf(r.right.charAt(i + 1))))) { // A → aBb

                                    list.add(r.right.charAt(i + 1));
                                } else {
                                    list.addAll(firstFollowTable.get(String.valueOf(r.right.charAt(i + 1))).getFirst()); // A -> aBC
                                }
                            } else {
                                try {
                                    //System.out.println(r.left.charAt(0));
                                    list.addAll(firstFollowTable.get(r.left).getFollow());
                                } catch(Exception e) {
                                }
//                                if(firstFollowTable.get(r.left.charAt(0)).getFollow().size() == 0) {
//                                    list.addAll(firstFollowTable.get(r.left.charAt(0)).getFollow()); // A → aB
//
//                                } else {
//                                    firstFollowTable.get(r.left.charAt(0)).setFollow(getFollow(r.left));
//                                    list.addAll(firstFollowTable.get(r.left.charAt(0)).getFollow()); // A → aB
//
//                                }

                            }
                      //  }
                    }
                }
//                if (list.size() == listSize) {
//                    for (int i = 0; i < r.right.length(); i++) {
//                        if (String.valueOf(r.right.charAt(i)).equals(left) &&  !r.left.equals(left)) {
//                            if (i < r.right.length() - 1) {
//                                if (!nonterminals.contains(String.valueOf(r.right.charAt(i + 1)))) {
//
//                                    list.add(r.right.charAt(i + 1));
//                                }
//                            } else {
//                                //System.out.println(left);
//                                list.add('$');
//                            }
//                        }
//                    }
//                }
            }
            //index++;
        }

//        List<Character> list1 = new ArrayList<>();
//        list1.addAll(list);
        return list;
    }

    public void constructFirstAndFollowTable() {
        for(int i = rules.size() - 1; i >= 0; i --){
                firstFollowTable.put(rules.get(i).left, new FirstFollow(getFirst(rules.get(i).left),new HashSet<Character>()));


        }
        Set set = new HashSet();
        set.add('$');
        firstFollowTable.get(rules.get(0).left).setFollow(set);

        boolean changes;
        do {
            changes = false;
            for(int i = 1; i < rules.size(); i ++){
                Set<Character> followBefore =  firstFollowTable.get(rules.get(i).left).getFollow();
                firstFollowTable.get(rules.get(i).left).setFollow(getFollow(rules.get(i).left));
                Set<Character> followAfter =  firstFollowTable.get(rules.get(i).left).getFollow();
                if(followBefore.size() != followAfter.size()) {
                    changes = true;
                }
            }
        } while (changes);


//        for(int i = 0; i < rules.size(); i ++){
//            firstFollowTable.get(rules.get(i).left).setFollow(getFollow(rules.get(i).left));
//
//
//        }
    }
    public void addNonterminals() {
        rules.stream().forEach(r -> nonterminals.add(r.left));
    }

    public Production getProduction(Rule r) {
        Production p = new Production();
        p.nonterminal = r.left;
        for(int i = 0; i < r.right.length(); i++) {
            p.stack.add(String.valueOf(r.right.charAt(i)));
        }
        List<Character> list = new ArrayList<>();
        list.addAll(firstFollowTable.get(r.left).getFollow());
        p.lookahead = list;
        return p;
    }

    public List<Production> getProductionsFor(String nonterminal) {
        List<Production> productions = new ArrayList<>();
        rules.stream().forEach(r -> {
            if(r.left.equals(nonterminal)) {
                Production p = getProduction(r);
                productions.add(p);
            }
        });
        return productions;
    }

    public List<Production> applyClosureTo(List<Production> productionList) {
        List<Production> productions = new ArrayList<>();
        List<String> nonTerm = new ArrayList<>();
        productionList.stream().forEach(p -> {
            if(p.dotPosition < p.stack.size()) {
                if(nonterminals.contains(p.stack.get(p.dotPosition))) {
                    if(!nonTerm.contains(p.stack.get(p.dotPosition))) {
                        productions.addAll(getProductionsFor(p.stack.get(p.dotPosition)));
                        nonTerm.add(p.stack.get(p.dotPosition));
                    }
                    productions.addAll(applyClosureTo(productions));
                }

            }

        });

        return productions;
    }

    // get all productions with dot in front of the cost symbol

    public List<Production> getAllForCost(String cost, List<Production> vertex) {
        List<Production> list = new ArrayList<>();
        vertex.stream().forEach(v -> {
            if (v.dotPosition >= v.stack.size()) {
                return;
            }
            if(v.stack.get(v.dotPosition).equals(cost)) {
                int newDot = v.dotPosition + 1;
                Production p = new Production(v.nonterminal, v.stack, v.lookahead, newDot);
                list.add(p);
            }
        });
        return list;
    }

    public List<List<Production>> addNeighbors(OrientedGraph<List<Production>> graph, List<Production> vertex) {
        List<String > costList = new ArrayList<>();
        List<List<Production>> vertexList = new ArrayList<>();
        vertex.stream().forEach(v -> {
            if (v.dotPosition >= v.stack.size()) {
                return;
            }
            String cost = v.stack.get(v.dotPosition);
            List<Production> prodForCost = getAllForCost(cost, vertex);
            List<Production> newVertex = new ArrayList<>();
            newVertex.addAll(prodForCost);
            newVertex.addAll(applyClosureTo(prodForCost));

            if(!graph.contains(newVertex)) {
                counter = counter + 1;
                graph.addVertex(newVertex, counter);
                vertexList.add(newVertex);
            }
            if(!costList.contains(cost)) {
                costList.add(cost);
                try {
                    //System.out.println(newVertex.toString());
                    graph.addEdge(vertex,newVertex,cost);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }



        });
        return vertexList;

    }

    public void addReductions(List<Production> p, OrientedGraph<List<Production>> graph, HashMap<String, String> map) {
            p.stream().forEach(prod -> {
                for(int i = 0; i < rules.size(); i ++) {
                    if (prod.dotPosition == prod.stack.size() && rules.get(i).left.equals(prod.nonterminal)) {
                        String right = "";
                        for (String c : prod.stack) {
                            right += c;
                        }
                        if (right.equals(rules.get(i).right)) {
                            for (Character c : firstFollowTable.get(rules.get(i).left).getFollow()) {

                                if (i == 0) {
                                    map.put(String.valueOf(c), "accept");
                                } else {
                                    map.put(String.valueOf(c), "r" + i);
                                }
                            }
                        }

                    }
                }
            });

    }
    public void shift(String action, Stack computationStack, Stack inputStack, Stack resultStack) {
        computationStack.push(inputStack.pop());
        computationStack.push(action.substring(1, action.length()));
    }

    public void reduce(String action, Stack computationStack, Stack inputStack, Stack resultStack) {

        String symbol;
        String rightSide;

        symbol = rules.get(Integer.parseInt(action.substring(1,action.length()))).left;
        rightSide = rules.get(Integer.parseInt(action.substring(1,action.length()))).right;
        resultStack.push(action.substring(1, action.length()));

        String rule = "";

        int lengthParsed = 0;
        for (int i = computationStack.size() - 1; i >= 0; i--) {
            if (!isNumeric(String.valueOf(computationStack.get(i)))){
                //System.out.println(rule);
                rule = String.valueOf(computationStack.get(i)) + rule;
                if (rightSide.equals(rule)) {
                    lengthParsed = computationStack.size() - i;
                }
            }
        }
        for(int i = 0; i < lengthParsed; i ++) {
            computationStack.pop();
        }

        String newStateAction = table.get(Integer.parseInt(String.valueOf(computationStack.peek()))).get(symbol);
        if(newStateAction != null) {
            computationStack.push(symbol);
            computationStack.push(newStateAction.substring(1,newStateAction.length()));

        }
    }
    // (computationStack, inputStack, resultStack)
    public void ParseString(String string) {
        Stack<Integer> resultStack = new Stack<>();
        Stack<String> inputStack = new Stack<>();
        Stack<String> computationStack = new Stack<>();

        computationStack.push("$");
        computationStack.push("0");

        inputStack.push("$");

        for(int i = string.length() - 1; i >= 0; i--) {
            inputStack.push(string.substring(i, i + 1));
        }
        String peek = null;
        while(true){
            String action = table.get(Integer.parseInt(String.valueOf(computationStack.peek()))).get(String.valueOf(inputStack.peek()));
            if (inputStack.size() == 1 && action == null) {
                System.out.println("reject => the string: "+string+" does not belong to L(G)");
                return;
            }

            if(inputStack.size() == 1 && table.get(Integer.parseInt(String.valueOf(computationStack.peek()))).get("$").equals("accept")) {
                break;
            }

            System.out.println(action);
            if(action == null) {
                System.out.println("reject => the string: "+string+" does not belong to L(G)");
                return;
            }
            if(action.charAt(0) == 's') {
                shift(action, computationStack, inputStack, resultStack);
            } else {
                //System.out.println("dsajd");
                reduce(action, computationStack, inputStack, resultStack);

            }

        }
        System.out.println(resultStack);
    }


    public void generateParsingAutomatum() {
        rules.add(0, new Rule(rules.get(0).left + "1", rules.get(0).left));
        addNonterminals();
        constructFirstAndFollowTable();
        OrientedGraph<List<Production>> graph = new OrientedGraph<>();
        List<Production> vertex = new ArrayList<>();

        Production prod = new Production();
            prod.nonterminal = rules.get(0).left;
            for(int i = 0; i < rules.get(0).right.length(); i++) {
                prod.stack.add(String.valueOf(rules.get(0).right.charAt(i)));
            }
        List<Character> list2 = new ArrayList<>();
        list2.addAll(firstFollowTable.get(rules.get(0).left).getFollow());
            prod.lookahead = list2;
            vertex.add(prod);
        vertex.addAll(applyClosureTo(vertex));
        graph.addVertex(vertex, counter);
        List<List<Production>> vertexList = addNeighbors(graph, vertex);
        while (vertexList.size() > 0) {
            List<List<Production>> newList = new ArrayList<>();
            for(List<Production> list : vertexList) {
                newList.addAll(addNeighbors(graph, list));
            }

            vertexList.clear();
            vertexList.addAll(newList);
        }

        for(List<Production> p: graph.getGraph().keySet()) {
            try {
                HashMap<String, String> map = new HashMap<>();
                if(graph.getGraph().get(p).neighbors.size() > 0){
                    graph.getGraph().get(p).neighbors.stream().forEach(n -> {
                        map.put(n.weight, "s"+n.to.tag);
                    });
                    addReductions(p, graph, map);
                } else {
                    addReductions(p, graph, map);
                }
                table.put(graph.getGraph().get(p).tag, map);


            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println(rules);

        System.out.println(table);
        System.out.println(firstFollowTable);

        //ParseString("c<a>dea;fg(){fa;a=b;jpa;}");
        //ParseString("c<a>");

        ParseString("acccd");


    }
}

