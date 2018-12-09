print ("""P2. Concurs

La un concurs de algoritmica, in urma evaluarii solutiilor oferite,
comisia de evaluare a inregistrat intr-un sir punctajele obtinute
de catre participanti  in urma rezolvarii problemelor si le-a memorat
intr-un sir (pe pozitia i se afla punctajul celui de-al i-lea participant).
Ajutati comisia sa efectueze in mod repetat urmatoarele functionalitati oferite
de program (fiecare functionalitate este insotita de exemple):

""")
from f_variabile import *
from f_functii import *
def initOptionsList(l):
    l.append("1. Adauga rezultatul unui nou participant in sir.")
    l.append("2. Modifica punctajele din sir (in urma contestatiilor unor participanti).")
    l.append("3. Tipareste participantii al caror punctaj intruneste anumite proprietati.")
    l.append("4. Obtine diferite caracteristici ale unor participanti")
    l.append("5. Filtreaza punctajele.")
    l.append("6. Reface ultima operatie care a modificat sirul punctajelor.")
    l.append("7. Tipareste sirul.")
    l.append("X. Exit")

def initCommandsList():
        l=[ui_1, ui_2, ui_3, ui_4, ui_5, ui_6, ui_7]
        return l

def main():   
    global y
    global n
    optionsList=[] #optiunile meniului
    commandsList=[] #comenzile corespunzatoare optiunilor meniului
    currentList=[10,20,30,40,50,60,70,80,90]
    initOptionsList(optionsList)
    commandsList=initCommandsList()
    y.append(currentList)
    while True:
        for i in range (0, len(optionsList)):
            print(" " + optionsList[i])
        op=input(">>>")
        if op == "X" or op == "x":
            break
        try:
            currentList = commandsList[int(op)-1](currentList)
        except ValueError as ex:
            print("Nu ati introdus o valoare numerica")
        except IndexError as ex:
            print("Nu ati introdus o optiune valida")
    return y
main()
