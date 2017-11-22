package controller;

import controller.FiniteStateAutomata;
import model.Atom;
import model.FIP;

import java.io.*;
import java.util.*;
import java.util.regex.Pattern;


/**
 * Created by andrapop on 2017-10-22.
 */
public class LexicalAnalyzer {
    private HashMap<String, Integer> reservedWords;
    private HashMap<String, Integer> separators;
    private HashMap<String, Integer> operators;
    private Vector<String> atoms;

    private HashMap<String, Integer> symbolTableIdentifiers;
    private HashMap<String, Integer> symbolTableConstants;
    private Vector<FIP> fip;

    private FiniteStateAutomata idFSA;
    private FiniteStateAutomata constFSA;
    private Scanner scanner;

    //private int start;

    public LexicalAnalyzer() {
        //citirea atomilor din fisiere
        reservedWords = initReserved("reservedWords.txt");
        separators = initReserved("seperators.txt");
        operators = initReserved("operators.txt");

        symbolTableIdentifiers = new HashMap<>();
        symbolTableConstants = new HashMap<>();
        fip = new Vector<>(); // (atomCode, posST)
        atoms = new Vector<>();

        this.idFSA = new FiniteStateAutomata(null);
        this.constFSA = new FiniteStateAutomata(null);
        scanner = new Scanner(System.in);
    }


    public void generateFSA() {
        // identifers of maximum 8 characters
        this.idFSA.addState("q0", true, false);
        List<Character> allNumbers = new ArrayList<>();
        allNumbers.add('0');
        allNumbers.add('1');
        for (int i = 1; i < 9; i++) {
            this.idFSA.addState("q" + i, false, true);
            allNumbers.add((char) ((i + 1) + '0'));
        }
        List<Character> allLetters = new ArrayList<>();
        for (char letter = 'a'; letter <= 'z'; letter++) {
            allLetters.add(letter);
            allLetters.add(Character.toUpperCase(letter));
            this.idFSA.addTransition("q0", "q1", Character.toString(letter));
        }
        this.idFSA.addTransition("q0","q1","_");
        for (int i = 1; i < 8; i++) {
            final int j = i;
            allLetters.stream().forEach(c -> this.idFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(c)));
            allNumbers.stream().forEach(n -> this.idFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(n)));
        }

        //constants
        this.constFSA.addState("q0", true, false);

        //character literals
        this.constFSA.addState("q3", false, true);
        this.constFSA.addState("q1", false, false);
        this.constFSA.addState("q2", false, false);
        this.constFSA.addTransition("q0", "q1", "\'");
        this.constFSA.addTransition("q2", "q3", "\'");
        allLetters.stream().forEach(c -> this.constFSA.addTransition("q1", "q2", Character.toString(c)));
        allNumbers.stream().forEach(n -> this.constFSA.addTransition("q1", "q2", Character.toString(n)));

        //integers
        this.constFSA.addState("q4", false, false);
        this.constFSA.addTransition("q0", "q4", "+");
        this.constFSA.addState("q5", false, true);
        allNumbers.stream().filter(n -> n != 0).forEach(nr -> this.constFSA.addTransition("q4", "q5", Character.toString(nr))); //+23
        for (int i = 5; i < 13; i++) {
            final int j = i;
            this.constFSA.addState("q" + (i + 1), false, true);
            allNumbers.stream().forEach(n -> this.constFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(n)));
        }
        this.constFSA.addState("q14", false, false);
        this.constFSA.addTransition("q0", "q14", "-");
        this.constFSA.addState("q15", false, true);
        allNumbers.stream().filter(n -> n != 0).forEach(nr -> this.constFSA.addTransition("q14", "q15", Character.toString(nr))); //-23
        for (int i = 15; i < 24; i++) {
            final int j = i;
            this.constFSA.addState("q" + (i + 1), false, true);
            allNumbers.stream().forEach(n -> this.constFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(n)));
        }

        this.constFSA.addState("q25", false, true); // 23
        allNumbers.stream().forEach(nr -> this.constFSA.addTransition("q0", "q25", Character.toString(nr)));
        for (int i = 25; i < 33; i++) {
            final int j = i;
            this.constFSA.addState("q" + (i + 1), false, true);
            allNumbers.stream().forEach(n -> this.constFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(n)));
        }

        // float
        this.constFSA.addState("q34", false, false);
        this.constFSA.addTransition("q25", "q34", ".");
        allNumbers.stream().forEach(n -> this.constFSA.addTransition("q34", "q25", Character.toString(n)));

        // string
        this.constFSA.addState("q35", false, false);
        this.constFSA.addTransition("q0", "q35", "\"");
        for (int i = 35; i < 39; i++) {
            final int j = i;
            this.constFSA.addState("q" + (i + 1), false, false);
            allNumbers.stream().forEach(n -> this.constFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(n)));
            allLetters.stream().forEach(n -> this.constFSA.addTransition("q" + j, "q" + (j + 1), Character.toString(n)));
        }
        this.constFSA.addState("q40", false, true);
        this.constFSA.addTransition("q39", "q40", "\"");

    }

    //citire din fisiere (pt operatori,separatori si cuvinte rezervate)
    private HashMap<String, Integer> initReserved(String file) {
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
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            int i = 1;
            while ((line = br.readLine()) != null) {
                detectAtoms(line, i);
                i++;
            }
        } catch (IOException e) {
            System.out.println("Fisierul nu a fost gasit!");
        }
    }

    //detectarea atomilor dintr-o linie
    private void detectAtoms(String line, int index) {
        int i = 0;
        line = line.replaceAll("\t", " ");    //inlocuiesc tab-urile cu spatii
        StringBuilder atom = new StringBuilder();
        jump:
        while (i <= line.length()) {
            if (i == line.length()) {        //a ajuns la sf si atomul e !=0, il adaug
                if (atom.length() != 0) {
                    if (isValidAtom(atom.toString())) {
                        atoms.add(atom.toString());
                    } else {
                        System.err.printf("Eroare lexicala la atomul %s pe linia %d", atom, index);
                        System.err.println();

                    }
                }
                return;
            }
            String currentChar = line.substring(i, i + 1); //iau caracterul curent
            if (currentChar.equals(" ")) {
                if (atom.length() != 0) {
                    if (!isValidAtom(atom.toString())) {
                        System.err.printf("Eroare lexicala la atomul %s pe linia %d ", atom, index);
                    } else {
                        atoms.add(atom.toString());
                        atom = new StringBuilder();
                    }
                }
                i++;
                continue jump;
            } else {
                if (operators.containsKey(currentChar) && constFSA.isAccepted(line.substring(i - 1, i))) { // constante float
                    atom.append(currentChar);
                    i++;
                } else if (operators.containsKey(currentChar) && (line.substring(i - 1, i).equals("\'") || line.substring(i - 1, i).equals("\""))) { // constante caracter/string
                    atom.append(currentChar);
                    i++;
                } else if (operators.containsKey(currentChar) && i + 1 < line.length() && line.substring(i + 1, i + 2).equals("0")) { // in the case of an atom of the form : +0 (lexically incorrect)
                    atom.append(currentChar);
                    i++;
                } else if (separators.containsKey(currentChar) || operators.containsKey(currentChar)) {
                    if (operators.containsKey(currentChar) && i + 1 < line.length() && operators.containsKey(line.substring(i + 1, i + 2))) { // >= operator din doua caractere
                        currentChar = line.substring(i, i + 2);
                        i++;
                    }
                    if (atom.length() != 0 && isValidAtom(atom.toString())) {
                        atoms.add(atom.toString());
                    }
                    if (isValidAtom(currentChar)) {
                        atoms.add(currentChar);
                        atom = new StringBuilder();
                        i++;
                    } else {
                        System.err.printf("Eroare lexicala la atomul %s pe linia %d ", atom, index);
                    }

                } else {
                    atom.append(currentChar);
                    i++;
                }
            }

        }

    }

    private int getPositionFromConstST(String atom) {
        return symbolTableConstants.get(atom);
    }

    private int getPositionFromIdST(String atom) {
        return symbolTableIdentifiers.get(atom);
    }

    private boolean idSTcontainsAtom(String atom) {
        if (symbolTableIdentifiers.containsKey(atom)) {
            return true;
        }
        return false;
    }

    private boolean constSTcontainsAtom(String atom) {
        if (symbolTableConstants.containsKey(atom)) {
            return true;
        }
        return false;
    }

    private boolean isValidAtom(String atom) {
        if (constFSA.isAccepted(atom.toString()) || reservedWords.containsKey(atom) || operators.containsKey(atom) || separators.containsKey(atom) || idFSA.isAccepted(atom)) {
            return true;
        }
        return false;
    }

    // Generate model.FIP, idST, constST
    public void generateTables(String file) {
        getText(file);
        for (String atom : atoms) {
            if (reservedWords.containsKey(atom) || operators.containsKey(atom) || separators.containsKey(atom)) {
                fip.add(new FIP(getCode(atom), 0));
            } else {
                if (idFSA.isAccepted(atom)) {
                    if (!idSTcontainsAtom(atom) && !constSTcontainsAtom(atom)) {
                        if (atom.length() <= 8) {    //identificator de lungime cel mult 8 caractere :)
                            symbolTableIdentifiers.put(atom, atom.hashCode());
                        } else {
                            System.err.printf("Eroare: Identificatorul %s este de lungime > 8", atom);
                            System.err.println();
                            return;
                        }
                    }
                    fip.add(new FIP(reservedWords.get("identifier"), (getPositionFromIdST(atom))));
                } else if (constFSA.isAccepted(atom)) {
                    if (!idSTcontainsAtom(atom) && !constSTcontainsAtom(atom)) {
                        symbolTableConstants.put(atom, atom.hashCode()); // val functiei de hash
                    }
                    fip.add(new FIP(reservedWords.get("constant"), (getPositionFromConstST(atom))));
                } else {
                    System.err.printf("Eroare lexicala la atomul %s", atom);
                    System.err.println();
                    return;
                }
            }
        }
        writeToFiles("model.FIP.txt", "idST.txt", "constST.txt");
    }

    //ia codul unui atom
    private int getCode(String atom) {
        if (reservedWords.containsKey(atom)) {
            return reservedWords.get(atom);
        }
        if (separators.containsKey(atom)) {
            return separators.get(atom);
        } else {
            return operators.get(atom);
        }
    }

    private void writeToFiles(String FIP, String idST, String constST) {
        try (BufferedWriter bwFIP = new BufferedWriter(new FileWriter(FIP, false))) {
            for (FIP fip : fip) {
                if (bwFIP != null) {
                    bwFIP.write(fip.getAtomCode() + "|" + fip.getPosST());
                }
                bwFIP.newLine();
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea in fisierul model.FIP.txt");
        }

        try (BufferedWriter bwTS = new BufferedWriter(new FileWriter(idST, false))) {
            for (Map.Entry<String, Integer> e : symbolTableIdentifiers.entrySet()) {
                if (bwTS != null) {
                    bwTS.write(e.getKey() + '|' + e.getValue());
                }
                bwTS.newLine();
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea in fisierul idST.txt");
        }

        try (BufferedWriter bwTS = new BufferedWriter(new FileWriter(constST, false))) {
            for (Map.Entry<String, Integer> e : symbolTableConstants.entrySet()) {
                if (bwTS != null) {
                    bwTS.write(e.getKey() + '|' + e.getValue());
                }
                bwTS.newLine();
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea in fisierul constST.txt");
        }

    }


    public FiniteStateAutomata getIdFSA() {
        return idFSA;
    }

    public FiniteStateAutomata getConstFSA() {
        return constFSA;
    }
}
