package model;

/**
 * Created by andrapop on 2017-10-22.
 */
public class FIP {
    public FIP(int atomCode, int posST) {
        this.atomCode = atomCode;
        this.posST = posST;
    }

    public int getAtomCode() {
        return atomCode;
    }

    public void setAtomCode(int atomCode) {
        this.atomCode = atomCode;
    }

    public int getPosST() {
        return posST;
    }

    public void setPosST(int posST) {
        this.posST = posST;
    }

    private int atomCode;
    private int posST;


}
