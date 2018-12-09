from f_variabile import *
from f_functii_secundare import *
def ui_1(l):
    #descriere:adauga/insereaza un elev nou in lista
    #date int: reprezentand lista elevilor
    #date out:lista de elevi modificata dupa voia utilizatorului
    global y
    global n
    n=n+1
    a=input("doriti sa adaugati un elev? ")
    if a=="DA" or a=="da":
        b=int(input("ce nota are respectivul?" ))
        l=adauga(l,b)
    if a=="NU" or a=="nu":
        b=input("doriti sa inserati o nota? ")
        if b=="DA" or b=="da":
            c=int(input("pe ce pozitie? "))
            d=int(input("ce nota? "))
            l=insert(l,c,d)
    y.append(l)
    return l

def ui_2(l):
    #descriere:stergerea unui elev, stergerea unei secvente/inlocuirea unui elev
    #date int: reprezentand lista elevilor
    #date out:lista de elevi modificata dupa voia utilizatorului
    q=[]
    global y
    global n
    a=input("doriti sa sergeti un elev? ")
    if a=="DA" or a=="da":
        b=int(input("ce pozitie are elevul?" ))
        l=sterge(l,b)
    elif a=="NU" or a=="nu":
        b=input("doriti sa stergeti o secventa? ")
        if b=="DA" or b=="da":
            c=int(input("pe ce pozitie? "))
            d=int(input("pana la ce pozitie? "))
            l=sterge_secventa(l,c,d)
        if b=="nu" or b=="NU":
            a=input("doriti sa inlocuiti un elev? ")
            if a=="DA" or a=="da":
                c=int(input("de pe ce pozitie? "))
                d=int(input("cu ce nota? "))
                l[c]=d
    n=n+1
    y.append(l)
    return l
def ui_3(l):
    #descriere:tipareste elevii in functie de vrutele utilizatorului
    #date in:l, unde l este lista de elevi
    #date out:-
    global y
    global n
    q=list()
    a=input("doriti sa tipariti elevii cu punctaj mai mic ca 40? ")
    if a=="DA" or a=="da":
        for i in range (0, len(l)):
            if l[i]<=40:
                print (i, l[i])
    elif a=="NU" or a=="nu":
        b=input("doriti sa tipariti in ordinea punctajelor? ")
        if b=="DA" or b=="da":
            q=l
            q.sort()
            for i in range (0, len(q)):
                print (q[i])
        else:
            a=input("doriti sa tipariti elevii cu note mai mari decat 90? ")
            if a=="DA" or a=="da":
                for i in range (0, len(l)):
                    if l[i]>=90:
                        print (i, l[i])
    return l

def ui_4(l):
    #descriere:calculeaza media aritmetica/punctajul minim/punctajele multiple de 10 din lista l
    #date in:l, unde l reprezinta lista elevilor
    #date out:afiseaza in consola media aritmetica/punctajul minim/punctajele multiple de 10 din lista l
    global y
    global n
    a=input("doriti sa faceti media aritmetica? ")
    if a=="DA" or a=="da":
        b=int(input("ce pozitie are elevul 1?" ))
        c=int(input("ce pozitie are ultimul elev?" ))
        med=media_aritmetica(l,b,c)
        print ("media aritmetica cu aproximatie este:", med)
    elif a=="NU" or a=="nu":
        b=input("doriti sa vedeti punctajul minim dintr-o secventa? ")
        if b=="DA" or b=="da":
            b=int(input("ce pozitie are elevul 1?" ))
            c=int(input("ce pozitie are ultimul elev?" ))
            minn=minim(l,b,c)
            print ("numarul minim din secventa este: ", minn)
        else:
            a=input("doriti sa tipariti punctejele din dintr-0 secventa care sunt multiplii de 10?  ")
            if a=="DA" or a=="da":
                b=int(input("ce pozitie are elevul 1?" ))
                c=int(input("ce pozitie are ultimul elev?" ))
                for i in range(b,c+1):
                    if l[i]%10==0:
                        print (l[i])
    return l

def ui_5(l):
    #descriere:filtreaza sa ramana doar participantii cu note multiplu de 10/note mai mari de 70
    #date in:l, unde l reprezinta lista elevilor
    #date out:modifica lista l in functie de filtrele aplicate de utilizator
    global n
    global y
    a=input("doriti sa filtrati sa ramana doar participantii cu note multiplu de 10? ")
    if a=="DA" or a=="da":
        l=filtrare_10(l)
    elif a=="NU" or a=="nu":
        b=input("doriti sa filtrati sa ramana doar participantii cu note mari de 70?  ")
        if b=="DA" or b=="da":
            l=filtrare_70(l)

    n=n+1
    y.append(l)
    return l
def ui_6(l):
    #descriere:functia elimina ultiam operatie eceftuata
    #date in:l, unde l reprezinta lista elevilor
    #date out:
    global y
    global n
    a=len(y)-1
    a=input("undo?")
    if a=="da" or a=="DA":
        l=y[a]
        del y[n]
        n=n-1        
        
    return l
def ui_7(l):
    #descriere:
    #date in:
    #date out:
    global y
    for i in range (0, len(l)):
        print (l[i])
    print (y)
    return l
