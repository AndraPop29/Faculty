
def adauga(l,x):
    #descriere:adauga elementul x in lista l
    #date in:l,lista elevilor; x elementul de adaugat
    #date out:lista l modificata
    l=l+[x]
    return l
def insert(l,c,d):
    #descriere:insereaza in lista l pe pozitia c elementul d
    #date in:l, lista elevilor; c pozitia de inserat, d, nota de inserat
    #date out: lista l modificata
    l=l[:c]+[d]+l[c:]
    return l
def sterge(l,b):
    #descriere:sterge din lista l pozitia b
    #date in:l, lista elevilor; b pozitia care trebuie stearsa
    #date out:lista modificata
    l=l[:b]+l[b+1:]
    return l
def sterge_secventa(l,c,d):
    #descriere:sterge din lista l secventa care incepe de la c si se termina la d
    #date in:l,lista elevilor;c,d parametrii intre care elementele trebuie eliminate
    #date out:lista l modificata
    q=l[:c]+l[d+1:]
    return q
def inlocuire(l,c,d):
    #descriere:functia inlocuieste nota de pe pozitia c cu nota d
    #date in:l lista elevilor; c pozitia elevului, d nota care trebuie inlcuita
    #date out:lista l modificata
    l[c]=d
    print(l)
    return l
def media_aritmetica(l,b,c):
    #descriere:calculeaza media aritmetica de pe pozitia b pana pe pozitia c
    #date in:l,lista elevilor,b,c pozitiile intre care se calculeaza media aritmetica
    #date out:media aritmetica a notelor elevilor de pe pozitiile b pana la c
    med=0
    q=0
    for i in range (b,c+1):
        med=med+l[i]
        q=q+1
    med=med/q
    return med
def minim(l,b,c):
    #descriere:afiseaza nota minica a elevilor din intervalul (b,c) 
    #date in:l, lista elevilor:b,c parametriii intre care se cauta nota minima
    #date out:minimul notelor dintre b si c
    minn=101
    for i in range (b,c+1):
        if(minn>=l[i]):
            minn=l[i]
    return minn
def filtrare_10(l):
    #descriere:filtreaza lista l astfel incat raman doar elevii cu note nultiplu de 10
    #date in:l, lista elevilor
    #date out:l, lista modificata unde sunt doar elevii cu note multiplu de 10
    q=[]
    for i in range (0,len(l)):
        if(l[1]%10==0):
            q=q+[l[i]]
    return q
def filtrare_70(l):
    #descriere:filtreaza lista l ramanand doar elevii cu note mai mari de 70
    #date in:l, lista elevilor
    #date out:l, lista elevilor care contine de aceasta data doar eleii cu  note mai mari de 70
    q=[]
    for i in range (0,len(l)):
        if(l[i])>70:
            q=q+[l[i]]
    return q