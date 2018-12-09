
from Utilities import *
def readAtransaction():
    """
    Description:reads the element of a transaction-amount,type,apartment
    Input:-
        preconditions:-
    Output:t or -1
        postconditions: t is a list, t=[amount, type, apartment]
                        -1 if the transaction isn't valid
    """
    print("Enter transaction data: \n")
    amount=float(input("amount: "))
    typ=input("type: ")
    ap=int(input("apartment: "))
    if(ap<0 or amount<0):
        return -1
    else:
        t=[amount, typ, ap]
        return t
def printList(l):
    '''
    Description: prints the list of apartments
    Input:l
    Prec:l-list of apartments
    Output:-
    Post:-
    '''
    if(len(l)>0):
        print(l)
    else:
        print("No apartments")
def printListTransactions(l):
    print(l)

def printMenu():
    str=" Commands: \n"
    str=str+ "\t 1= add a transaction \n"
    str=str+ "\t 2= Modify expenses from list \n"
    str=str+ "\t 3=Write the expenses having different properties. \n"
    str=str+ "\t 4=Obtain different characteristics of expenses \n"
    str=str+ "\t 5=Filter \n"
    str=str+ "\t 6=Undo \n"
    str=str+ "\t 7=Redo \n"
    str=str+ "\t 8=Print list \n"
    str=str+ "\t 0= exit app \n"
    print (str)

def printMenu2():
    str=" Commands: \n"
    str=str+ "\t 1=remove all expenses from one ap \n"
    str=str+ "\t 2=remove from ap1 to ap2 \n"
    str=str+ "\t 3=remove type \n"
    str=str+ "\t 4=replace for an apartment the expense, with a given type \n"
    print (str)
def printMenu3():
    str="Commands: \n"
    str=str+ "\t 1=greater than a sum \n"
    str=str+ "\t 2=less than a sum, before an apartment \n"
    str=str+ "\t 3=all type \n"
    str=str+ "\t 4=balance apartment \n"
    print(str)
def printMenu4():
    str="Commands: \n"
    str= str+ "\t 1=sum type \n"
    str=str+ "\t 2=max ap \n"
    str=str+ "\t 3=asc sort apt \n"
    str=str+ "\t 4=desc sort type \n"
    print(str)
def printMenu5():
    str="Commands: \n"
    str= str+ "\t 1=filter type \n"
    str=str+ "\t 2=filter sum \n"
    print(str)
def validCommand(cmd):
    availableCmd=["1","2","3","4","5","6","7","8","0"]
    return cmd in availableCmd
def validCommand2(cmd):
    availableCmd=["1","2","3","4","5","6"]
    return cmd in availableCmd
def validCommand3(cmd):
    availableCmd=["1","2"]
    return cmd in availableCmd

def mainMenu():
    
  
    
    l=[]
    while True:
        printMenu()
        cmd=input("Enter option:")
        if validCommand(cmd):
            if cmd=="0":
                break
            else:
                if cmd=="1":
                     lundo=l[:]
                     tNew=readAtransaction()
                     while(tNew==-1):
                         print("give a valid transaction")
                         tNew=readAtransaction()
                         
                     ok=addAtransaction(l,tNew)
                     lredo=l[:]
                     if(not ok):
                         print("the transaction exists")
                     else:
                         print("transaction added with success")
                         
                else:
                    if cmd=="2":
                        printMenu2()
                        cmd=input("Enter command: ")
                        if validCommand2(cmd):
                            if cmd=="1":
                                lundo=l[:]
                                n=int(input("give apartment number:"))
                                if (findApartment(l,n)!=-1):
                                    while(findApartment(l,n)!=-1):
                                        removeExpenses_ap(l,n)
                                    print("the expenses were removed successfully")
                                else:
                                    print("No transactions for apartment 15 were found")
                                lredo=l[:]
                            elif cmd=="2":
                                a=int(input("give first ap"))
                                b=int(input("give second ap"))
                                ok=0
                                lundo=l[:]      
                                for i in range (a,b+1):
                                    if(findApartment(l,i)!=-1):
                                        while(findApartment(l,i)!=-1):
                                            removeExpenses_ap(l,i)
                                            ok=1
                                        print("the expenses have been removed successfully")
                                if ok==0:
                                     print("there are no transactions for apartments in the given interval")
                                lredo=l[:]  
                                       
                                        
                            elif cmd=="3":
                                tip=input("give type of expense to be removed:")
                                lundo=l[:]
                                if(findType(l,tip)!=-1):
                                    while(findType(l,tip)!=-1):
                                        removeExpenses_type(l,tip)
                                        print("the expenses have been removed successfully")
                                else:
                                    print("there are no expenses for the given type")
                                lredo=l[:]   
                            elif cmd=="4":
                                lundo=l[:]
                                ap=int(input("give ap number: "))
                    
                                tip=input("Give type of expense to be replaced: ")
                                su=float(input("give new expense: "))
                                if(ReplaceExpense(l,tip,ap,su)==True):
                                    print("The expense was replaced successfully")
                                else:
                                    print("There is no transaction in the list for apartment 12, having the indicated type")
                                lredo=l[:]
                       
                        else:
                            print("Enter a valid command")
                                        
                    elif cmd=="3":
                        printMenu3()
                        cmd=input("Enter option")
                        if(validCommand2(cmd)):
                            if(cmd=="1"):
                
                                l1=[]
                                lundo=l1[:]
                                for i in range(len(l)):
                                    t=l[i]
                                    n=float(input("Enter sum:"))
                                    if(overall_expense(l,t[2])>n):
                                        insertAp(l1,t[2])
                                lredo=l1[:]
                                printList(l1)       
                    
                            if(cmd=="2"):
                                l1=[]
                                lundo=l1[:]
                                ap=int(input("Before apartment:"))
                                n=float(input("Less than:"))
                                for i in range (0,len(l)):
                                        t=l[i]
                                        if(t[2]<ap and overall_expense(l,t[2])<n):
                                            insertAp(l1,t[2])
                                lredo=l1[:]
                                printList(l1)
                                
                            if(cmd=="3"):
                                typ=input("give type:")
                                if(findType(l,typ)!=-1):
                                    print(ExpType(l,typ))
                                else:
                                    print("no expenses for the given type")
        
                               
                            if(cmd=="4"):
                                ap=int(input("give apartment"))
                                print(overall_expense(l,ap))
                        else:
                            print("Enter a valid command")
                    elif(cmd=="4"):
                        printMenu4()
                        cmd=input("Enter option: ")
                        if(validCommand2(cmd)):
                            if(cmd=="1"):
                                typ=input("give type: ")
                                print(TotalExpense_type(l,typ))
                                    
                            if(cmd=="2"):
                                ap=int(input("give apartment:"))
                                if(findMaxE(l,ap)!="null"):
                                    print(MaxAp(l,ap))
                                else:
                                    print("no apartment registered")
                                    
                            if(cmd=="3"):
                                a=[]
                                lundo=a[:]
                                if(len(l)==0):
                                    print("Empty list")
                                else:
                                    ConstrList(l,a)
                                    sort_asc(a)
                                    print(a)
                                lredo=a[:]  
                            if(cmd=="4"):
                                a=[]
                                lundo=a[:]
                                if(len(l)==0):
                                    print("Empty list")
                                else:
                                    ConstrListTyp(l,a)
                                    sort_desc(a)
                                    print(a)
                                lredo=a[:]
                        
                        else:
                            print("Enter a valid command")
                    elif(cmd=="5"):
                        printMenu5()
                        cmd=input("Enter Option: ")
                        if(validCommand3(cmd)):
                            if(cmd=="1"):
                                lundo=l[:]
                                typ=input("Give type: ")
                                if(findType(l,typ)!=-1):
                                    FilterType(l,typ)
                                    
                                else:
                                    print("no such type in the list of expenses")
                                lredo=l[:]
                            elif(cmd=="2"):
                                lundo=l[:]
                                s=float(input("Give sum: "))
                                a=[]
                                ConstrList(l,a)
                                FilterSum(a,s)
                                if(len(a)==0):
                                    print("they don't exist")
                                else:
                                    printList(a)
                                lredo=l[:]
                                
                                
                        else:
                            print("Enter a valid command")
                    elif(cmd=="6"):
                        print(lundo)
                    elif(cmd=="7"):
                        if(lundo==lredo):
                            print("the list wasn't modified")
                        else:
                            print(lredo)
                        
                    elif(cmd=="8"):
                        printListTransactions(l)
                        
        else:
            print("Enter a valid command:")
        


