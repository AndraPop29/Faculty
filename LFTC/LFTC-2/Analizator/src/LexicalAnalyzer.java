import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


/**
 * Created by andrapop on 2017-10-22.
 */
public class LexicalAnalyzer {
    private HashMap<String, Integer> reservedWords;
    private HashMap<String, Integer> separators;
    private HashMap<String, Integer> operators;
    private Vector<String> atoms;

    private Pattern identifier;
    private Pattern constant;

    private HashMap<String, Integer> symbolTableIdentifiers;
    private HashMap<String, Integer> symbolTableConstants;
    private Vector<FIP> fip;

    //private int start;

    public LexicalAnalyzer() {
        //citirea atomilor din fisiere
        reservedWords = initReserved("reservedWords.txt");
        separators = initReserved("seperators.txt");
        operators = initReserved("operators.txt");

        //indicele de pornire
        //start = reservedWords.size() + operators.size() + separators.size() + 5;

        //sabloanele pt identificatori si constante
       //identifier = Pattern.compile("^[A-Za-z_]|[A-Za-z_]+[0-9]+|[A-Za-z_][A-Za-z_]+$");
        identifier = Pattern.compile("^[A-Za-z_][A-Za-z_0-9]*$");
        constant =  Pattern.compile("(0|[+|-]?[1-9]|[+|-]?[1-9][0-9]+$)|(^[+|-]?0.0+[1-9]+[0-9]*|[+|-]?0.[1-9]+[0-9]*|[+|-]?[1-9][0-9]+.[0-9]+|[+|-]?[1-9]+.[0-9]+$)|(^'[A-Za-z0-9]'$)|(^\"[A-Za-z0-9]+\"$)");

        symbolTableIdentifiers = new HashMap<>();
        symbolTableConstants = new HashMap<>();
        fip = new Vector<>(); // (atomCode, posST)
        atoms = new Vector<>();
    }

    //citire din fisiere (pt operatori,separatori si cuvinte rezervate)
    private HashMap<String, Integer> initReserved(String file){
        HashMap<String, Integer> lista = new HashMap<String, Integer>();
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String linie;
            while ((linie = br.readLine()) != null) {
                String[] elems = linie.split("@");
                if (elems.length < 2) {
                    System.err.println("Linie invalida " + linie);
                    continue;
                }
                Atom atom = new Atom(elems[0], Integer.parseInt(elems[1]));
                lista.put(elems[0], Integer.parseInt(elems[1]));
            }
        } catch (IOException e) {
            System.out.println("Could not find file!");
        }
        return lista;
    }

    public void getText(String file) {
        try (BufferedReader br = new BufferedReader(new FileReader(file))){
            String line;
            int i=1;
            while ((line = br.readLine()) != null){
                detectAtoms(line, i);
                i++;
            }
        } catch (IOException e) {
            System.out.println("Fisierul nu a fost gasit!");
        }
    }

    public String getTypeOfError(String atom) {
        if(atom.charAt(0) == '\'' || atom.charAt(atom.length() - 1) =='\'') {
            return ", stringul nu respecta specificatile pentru constantele caracter";
        }
        if(atom.charAt(0) == '\"' || atom.charAt(atom.length() - 1) =='\"') {
            return ", stringul nu respecta specificatile pentru constantele string";
        }
        if(atom.length() > 8) {
            return ", identificatorii nu pot fi mai lungi de 8 caractere";
        }
        if(!isIdentifier(atom)) {
            return ", stringul nu respecta specificatile pentru identificatori";
        }
        if(!isConstant(atom)) {
            return ", stringul nu respecta specificatile pentru constante";
        }
        return "";
    }

    //detectarea atomilor dintr-o linie
    private void detectAtoms(String line, int index){
        int i = 0;
        line = line.replaceAll("\t", " ");	//inlocuiesc tab-urile cu spatii
        StringBuilder atom = new StringBuilder();
        jump:
        while(i <= line.length()){
            if(i == line.length()){ 		//a ajuns la sf si atomul e !=0, il adaug
                if(atom.length() != 0) {
                    if (isValidAtom(atom.toString())) {
                        atoms.add(atom.toString());
                        atom = new StringBuilder();
                    } else {
                        System.err.printf("Eroare lexicala la atomul %s pe linia %d %s", atom, index, getTypeOfError(atom.toString()));
                    }
                }
                return;
            }
            String currentChar = line.substring(i, i+1); //iau caracterul curent
            if(currentChar.equals(" ")){
                if(atom.length() != 0){
                    if(!isValidAtom(atom.toString())) {
                        System.err.printf("Eroare lexicala la atomul %s pe linia %d %s", atom, index, getTypeOfError(atom.toString()));
                    } else {
                        atoms.add(atom.toString());
                        atom = new StringBuilder();
                    }
                }
                i++;
                continue jump;
            }
            else {
                if(isOperator(currentChar) && isConstant(line.substring(i-1,i))) { // constante float
                    //System.out.println(atom);
                    atom.append(currentChar);
                    i++;
                }
                else if(isOperator(currentChar) && (line.substring(i-1,i).equals("\'") || line.substring(i-1, i).equals( "\"" ))) { // constante caracter/string
                    atom.append(currentChar);
                    i++;
                }

                else if(isOperator(currentChar) && i+1<line.length() && line.substring(i+1,i+2).equals("0")) { // in the case of an atom of the form : +0 (lexically incorrect)
                    atom.append(currentChar);
                    i++;
                }
                else if (isSeparator(currentChar) || isOperator(currentChar)){
                    if(isOperator(currentChar) && i+1<line.length() && isOperator(line.substring(i+1,i+2))){ // >= operator din doua caractere
                        currentChar = line.substring(i,i+2);
                        i++;
                    }
                    if (atom.length() != 0 && isValidAtom(atom.toString())){
                        atoms.add(atom.toString());
                    }
                    if(isValidAtom(currentChar)) {
                        atoms.add(currentChar);
                        atom = new StringBuilder();
                        i++;
                    } else {
                        System.err.printf("Eroare lexicala la atomul %s pe linia %d %s", atom, index, getTypeOfError(atom.toString()));
                    }

                } else {
                    atom.append(currentChar);
                    i++;
                }
            }

        }

    }

    private int getPositionFromConstST(String atom){
        return symbolTableConstants.get(atom);
    }

    private int getPositionFromIdST(String atom){
        return symbolTableIdentifiers.get(atom);
    }

    private boolean idSTcontainsAtom(String atom){
        if(symbolTableIdentifiers.containsKey(atom)) {
            return true;
        }
        return false;
    }

    private boolean constSTcontainsAtom(String atom){
        if(symbolTableConstants.containsKey(atom)) {
            return true;
        }
        return false;
    }

    private boolean isValidAtom(String atom) {
        if(isConstant(atom.toString()) || reservedWords.containsKey(atom) || operators.containsKey(atom) || isSeparator(atom)) {
            return true;
        }
        if(isIdentifier(atom) && atom.length() < 8) {
            return true;
        }
        return false;
    }

    // Generate FIP, idST, constST
    public void generateTables(String file) {
        getText(file);
        for (String atom : atoms) {
            if (reservedWords.containsKey(atom) || operators.containsKey(atom) || isSeparator(atom)) {
                fip.add(new FIP(getCode(atom), 0));
            } else {
                //System.out.println(atom);
                if (isIdentifier(atom) ) {
                    if (!idSTcontainsAtom(atom) && !constSTcontainsAtom(atom)) {
                        if(atom.length()<=8){	//identificator de lungime cel mult 8 caractere :)
                            symbolTableIdentifiers.put(atom,atom.hashCode());
                        } else{
                            System.err.printf("Eroare: Identificatorul %s este de lungime > 8", atom);
                            return;
                        }
                    }
                    fip.add(new FIP(reservedWords.get("identifier"), (getPositionFromIdST(atom))));
                } else if (isConstant(atom)) {
                    if (!idSTcontainsAtom(atom) && !constSTcontainsAtom(atom)) {
                        symbolTableConstants.put(atom,atom.hashCode()); // val functiei de hash
                    }
                    fip.add(new FIP(reservedWords.get("constant"), (getPositionFromConstST(atom))));
                } else {
                    System.err.printf("Eroare lexicala la atomul %s", atom);
                    return;
                }
            }
        }
        writeToFiles("FIP.txt","idST.txt","constST.txt");
    }

    private boolean isOperator(String operator){
        return operators.containsKey(operator);
    }

    private boolean isSeparator(String separator){
        return separators.containsKey(separator);
    }

    private boolean isIdentifier(String atom){
        Matcher m = identifier.matcher(atom);
        return m.matches();
    }

    private boolean isConstant(String atom){
        Matcher m = constant.matcher(atom);
        return m.matches();
    }

    //ia codul unui atom
    private int getCode (String atom) {
        if (reservedWords.containsKey(atom)){
            return reservedWords.get(atom);
        }
        if (separators.containsKey(atom)){
            return separators.get(atom);
        } else {
            return operators.get(atom);
        }
    }

    private void writeToFiles(String FIP, String idST, String constST) {
        try (BufferedWriter bwFIP = new BufferedWriter(new FileWriter(FIP,false))) {
            for (FIP fip : fip) {
                if (bwFIP != null) {
                    bwFIP.write(fip.getAtomCode()+"|"+fip.getPosST());
                }
                bwFIP.newLine();
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea in fisierul FIP.txt");
        }

        try (BufferedWriter bwTS = new BufferedWriter(new FileWriter(idST, false))) {
            for (Map.Entry<String, Integer> e : symbolTableIdentifiers.entrySet()) {
                if (bwTS != null) {
                    bwTS.write(e.getKey()+ '|' +e.getValue());
                }
                bwTS.newLine();
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea in fisierul idST.txt");
        }

        try (BufferedWriter bwTS = new BufferedWriter(new FileWriter(constST, false))) {
            for (Map.Entry<String, Integer> e : symbolTableConstants.entrySet()) {
                if (bwTS != null) {
                    bwTS.write(e.getKey()+ '|' +e.getValue());
                }
                bwTS.newLine();
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea in fisierul constST.txt");
        }

    }


}
