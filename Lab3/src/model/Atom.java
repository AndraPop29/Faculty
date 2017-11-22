package model;

/**
 * Created by andrapop on 2017-10-22.
 */
public class Atom {
    private String atomName;
    private int atomCode;


    public Atom(String atomName, int atomCode) {
        this.atomName = atomName;
        this.atomCode = atomCode;
    }

    public String getAtomName() {
        return atomName;
    }

    public void setAtomName(String atomName) {
        this.atomName = atomName;
    }

    public int getAtomCode() {
        return atomCode;
    }

    public void setAtomCode(int atomCode) {
        this.atomCode = atomCode;
    }

    @Override
    public String toString() {
        return "model.Atom{" +
                "atomName='" + atomName + '\'' +
                ", atomCode=" + atomCode +
                '}';
    }
}
