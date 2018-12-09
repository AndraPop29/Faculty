"""
5. APARTMENT BUILDING ADMINISTRATOR
Michael is the administrator of an apartment building and wants to manage the monthly expenses
for each apartment in the building. In order to complete this task, Michael needs an application to
store, for a certain month, the expenses for each apartment. Each expense will be stored in the
application through the following elements: amount, type of the expense (the administrator wants to
group the expenses in several predefined categories: such as water, heating, illuminating, gas, others).
Michael needs an application in order to repeatedly execute the following functionalities (each
functionality is exemplified):
1. Add a new transaction into the list.
insert 100, type at 25 – inserts at apartment 25 an expense of 100 RON having the given type
2. Modify expenses from the list.
remove 15 – removes all the expenses at apartment 15
remove from 5 to 10 – removes all the expenses from apartment 5 to apartment 10
remove type – removes all the expenses having the indicated type, from all the apartments
replace 12, type with 200 – replaces the amount for the expense having the specified type at
apartment 12 with 200 RON
3.Write the expenses having different properties.
greater than 100 - writes all the apartments with an overall expense greater than 100 RON
less than 100 before 15 - writes all the apartments with an overall expense less than 100 for apartments from 1 to 15 
all type – writes all the expenses having the specified type. 
balance 10 – computes the balance (total amount) for apartment 10 
4.Obtain different characteristics of expenses. 
sum type – writes the total amount for the expenses having the specified type.
 max 25 – writes the maximum expense per type for apartment 25 
asc sort apt – sorts the total expenses/apartment in an ascending order 
desc sort type - sorts the total expenses per type in a descending order
5.Filter
filter type – retains only the expenses having the specified type. 
filter 300 – retains only the overall expenses greater than 300 RON
6.        Undo the last operation
undo – the last operation that has modified the list of expenses is cancelled. 

"""


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
def verifyExistance(l,typ,ap):
    '''
    Description: verifies the existance of a transaction
    Input:l,typ,ap
        preconditions:l-list of transactions, typ-type of transaction, ap-apartment number
    Output:pos
        postconditions:pos=-1 if the transaction doesn't exist
                       pos=i, i the position in the list if the transaction exists
    '''
    pos=-1
    for i in range(0,len(l)):
        t=l[i]
        if(t[2]==ap and t[1]==typ):
            pos=i
    return pos
def InitialTest(l):
    l.append([100.5,'water',14])
    l.append([93.9, 'gas', 15])
    l.append([20, 'illuminating', 3])

def test_verifyExistance():
    l=[]
    InitialTest(l)

    assert verifyExistance(l,'water',14)==0
    assert verifyExistance(l,'gas',3)==-1
    assert verifyExistance(l,'illuminating',3)==2
def addAtransaction(l,t):
    """
    Description: adds a new transaction into the list
    Input:l,t
        Preconditions:l-list of transactions, t-the transaction to be added
    Output:result
        Postconditions: result=true if t is added
                        result=false if t is not added
    """
    pos=verifyExistance(l,t[1],t[2])
    if(pos==-1):
        l.append(t)
        return True
    else:
        return False
def test_addAtransaction():
    l=[]
    InitialTest(l)

    assert addAtransaction(l,[100, 'water', 14])==False
    assert addAtransaction(l,[21, 'gas', 2])==True
def findApartment(l,ap):
    """
    Description: searches for the transaction of a given apartment
    Input:l,ap
        Preconditions:l-list of transactions, ap-apartment to be found
    Output:pos
        Postconditions:pos=-1 if there is no transaction for ap in the list
                       pos=i, i the position in the list if ap exists
    """
    pos=-1
    for i in range(0,len(l)):
        t=l[i]
        if(t[2]==ap):
            pos=i
    return pos
def test_findApartment():
    l=[]
    InitialTest(l)
    assert findApartment(l,15)==1
    assert findApartment(l,21)==-1
def removeExpenses_ap(l,ap):
    """
    Description: deletes the transaction for a given apartment(if it is in the list)
    Input:l,ap
        Preconditions:l-list of students
                      ap-the apartment we need to delete the transaction from
    Output:result
        Postconditions:result=true, if we found and deleted the transaction
                       result=false, if the transaction is not in the list
    """
    pos=findApartment(l,ap)
    if(pos==-1):
        return False
    else:
        l.pop(pos)
        return True
def test_removeExpenses_ap():
    l=[]
    InitialTest(l)
    assert removeExpenses_ap(l,3)==True
    assert removeExpenses_ap(l,6)==False
def findType(l,typ):
    """
    Description: Searches for a transaction with a given type
    Input:l,typ
        Preconditions:l-list
                      type-type of transaction to be deleted
    Output:pos
        Postconditions:pos=-1, if the type is not in the list
                       pos=i,i the position of the transacton with the given type
    """
    pos=-1
    for i in range(0,len(l)):
        t=l[i]
        if(t[1]==typ):
            pos=i
    return pos
def test_findType():
    l=[]
    InitialTest(l)
    assert findType(l,'water')==0
    assert findType(l,'heating')==-1
def removeExpenses_type(l,typ):
    """
    Description:Removes transaction with a given type, if found
    Input:l,typ
        Preconditions:l-list
                      typ-type of transaction to be deleted
    Output:result
        Postconditions:result=true, if we find a transaction of a given type and delete it
                       result=false, if the transaction is not found, therefore not removed
    """
    pos=findType(l,typ)
    if(pos==-1):
        return False
    else:
        l.pop(pos)
        return True

def test_removeExpenses_type():
    l=[]
    InitialTest(l)
    assert removeExpenses_type(l,'water')==True
    assert removeExpenses_type(l,'heating')==False
def ReplaceExpense(l,typ,ap,su):
    """
    Description:Replaces the amount of a expense with a given type and apartment number
    Input:l, typ, ap
        Precond:l-list of transactions, typ-type of expense, ap-apartment number
    Output:result
        Postcond:result=true,if the transaction is found and the amount of the expense is successfully replaced
                 result=false, if the transaction is not found in the list
    """
    pos=verifyExistance(l,typ,ap)
    if(pos==-1):
        return False
    else:
        t=l[pos]
        t[0]=su
        return True
def test_ReplaceExpense():
    l=[[12.5,'water',12],[113,'gas',15],[145,'illuminating',12]]
    
    assert ReplaceExpense(l,'water',12,200)==True
    assert ReplaceExpense(l,'gas',11,100)==False
def overall_expense(l,ap):
    """
    Description: Computes the overall expense for a given apartment number
    Input:l,ap
    Prec:l-list of transactions, ap-the apartment number
    Output:su
    Post:su=the overall expense for the given apartment
    """
    su=0
    for i in range(0,len(l)):
        t=l[i]
        if(t[2]==ap):
            su=su+t[0]
    return su
def test_overall_expense():
    l=[[13.5,'water',2],[11.5,'gas',2],[3.5,'illuminating',1]]
    assert overall_expense(l,2)==25.0
    assert overall_expense(l,3)==0
    assert overall_expense(l,1)==3.5
def insertAp(l,ap):
    '''
    Description: inserts the apartment in the new list if it doesn't exist
    Input:l,ap
    Prec:l-list of apartments, ap-apartment number
    Output: -
    Post:-
    '''
    if(NoApart(l,ap)!=-1):
        l.append(ap)
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
def ExpType(l,typ):
    '''
    Description: Prints all the expenses havin the specified type
    Input:l,typ
    Prec:l-list of transactions
         typ-type of expense
    Output:-
    Post:-
    '''
    if(findType(l,typ)!=-1):
        for i in range(0,len(l)):
            t=l[i]
            if(t[1]==typ):
                print(t)
    else:
        print("no expenses for the given type")
    
def NoApart(l,ap):
    """
    Description: Verifies if there are expenses registered for a given apartment
    Input:l,ap
    Prec:l-list of transactions,ap-the given apartment number
    Output:result
    Post: result=True, if there is no apartment with the given number in the list
          result=False, if there is an apartment with the number of the variable ap
    """
    for i in range(0,len(l)):
        
        if l[i]==ap:
            return False
    return True
def test_NoApart():
    l=[12,1,3]
    assert NoApart(l,1)==False
    assert NoApart(l,4)==True
def TotalExpense_type(l,typ):
    """
    Description: Calculates the total sum for a type of expense
    Input:l,typ
    Prec: l-list of transactions, typ-type of expense
    Output:s
    Post:s=0, if there are no expenses  for the given type
         
    """
    s=0
    for i in range(0,len(l)):
        t=l[i]
        if(t[1]==typ):
            s=s+t[0]
    return s
def test_TotalExpense_type():
    l=[[13.5,'water',2],[11.5,'water',2],[3.5,'illuminating',1]]
    assert TotalExpense_type(l,'water')==25.0
    assert TotalExpense_type(l,'heating')==0

def findMaxE(l,ap):
    """
    Description: Return the maximum expense(type) for the specified apartment
    Input:l,ap
    Prec:l-list of transactions, ap-the apartment number
    Output:typ
    Post:typ="null", if there are no expenses registered for the specified apartment
         typ=the type of the highest expense
    """
    ma=0
    for i in range(0,len(l)):
        t=l[i]
        typ="null"
        ma=0
        for i in range(0,len(l)):
            t=l[i]
            if(t[2]==ap):
                if(t[0]>ma):
                    typ=t[1]
                    ma=t[0]
    return typ
def test_findMaxE():
    l=[[13.5,'water',2],[11.5,'gas',2],[3.5,'illuminating',1]]
    assert findMaxE(l,2)=='water'
    assert findMaxE(l,3)=='null'
def printMaxAp(l,ap):
    '''
    Description: Prints the maximum expense for an apartment, if it is in the list
    Input:l,ap
    Prec:l-list of transactions
         ap-apartment number
    Output:-
    Post:-

    '''
    typ=findMaxE(l,ap)
    if(typ!=-1):
        print(typ)
    else:
        print("no apartment registered")
def NoApart2(l,ap):
    """
    Description: Verifies if the apartment exist in the list of total expenses
    Input:l,ap
    Prec:l-list of total expenses, ap-the number of the apartment
    Output:result
    Post:result=True, if the apartment doesn't exist
         result=False if it exists
    """
    for i in range(0,len(l)):
        t=l[i]
        if(t[1]==ap):
            return False
    return True
        
def test_NoApart2():
    l=[[23.5,3],[35,2],[100,5]]
    assert NoApart2(l,3)==False
    assert NoApart2(l,7)==True
def ConstrList(l,a):
    '''
    Specification: Creates a list containing the total amount of expenses for each apartment
    Input:l,a
    Prec:l-list of transactions
         a-new list
    Output:-
    Post:-
    '''
    for i in range(0,len(l)):
        t=l[i]
        ex=overall_expense(l,t[2])
        if NoApart2(a,t[2]):
            a.append([ex,t[2]])
def sort_asc(l):
    """
    Description: Sorts a list of total expenses for apartments in an ascending order
    Input: l
    Prec: l-list of apartments with total expenses: l=[[total_expense1,ap1],[total_expense2,ap2],...]
    Output: -
    Post: -
    """
    for i in range(0,len(l)-1):
        for j in range(i+1,len(l)):
            x=l[i]
            y=l[j]
            if(x[0]>y[0]):
                au=l[i]
                l[i]=l[j]
                l[j]=au

def NoApart3(l,typ):
    for i in range(0,len(l)):
        t=l[i]
        if(t[1]==typ):
            return False
    return True
def test_NoApart3():
    l=[[2001.5,'water'],[3420,'gas'],[35.5,'illuminating']]
    assert NoApart3(l,'water')==False
    assert NoApart3(l,'heating')==True
def ConstrListTyp(l,a):
    '''
    Specification: Creates a list containing the total amount of expenses for each type
    Input:l,a
    Prec:l-list of transactions
         a-new list
    Output:-
    Post:-
    '''
    for i in range(0,len(l)):
        t=l[i]
        ex=TotalExpense_type(l,t[1])
        if NoApart3(a,t[1]):
            a.append([ex,t[1]])
def sort_desc(l):
    """
    Description: Sorts a list of total expenses per type in a descending order
    Input: l
    Prec: l-list of total expenses for each registered type: l=[[total_expense1,type1],[total_expense2,type2],...]
    Output:-
    Post:-
    """
    for i in range(0,len(l)-1):
        for j in range(i+1,len(l)):
            x=l[i]
            y=l[j]
            if(x[0]<y[0]):
                au=l[i]
                l[i]=l[j]
                l[j]=au
def printMenu():
    str=" Commands: \n"
    str=str+ "\t 1= add a transaction \n"
    str=str+ "\t 2= Modify expenses from list \n"
    str=str+ "\t 3=Write the expenses having different properties. \n"
    str=str+ "\t 4=Obtain different characteristics of expenses \n"
    str=str+ "\t 0= exit app \n"
    print (str)
def printMenu2():
    str=" Commands: \n"
    str=str+ "\t 1=remove all expenses from one ap \n"
    str=str+ "\t 2=remove from ap1 to ap2 \n"
    str=str+ "\t 3=remove type \n"
    str=str+ "\t 4=replace for an apartment the expense, with a given type \n"
    str=str+ "\t 0=exit app \n"
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
def validCommand(cmd):
    availableCmd=["1","2","3","4","0"]
    return cmd in availableCmd
def validCommand2(cmd):
    availableCmd=["1","2","3","4","0"]
    return cmd in availableCmd
def main():
    
    
    test_verifyExistance()
    test_addAtransaction()
    test_findApartment()
    test_removeExpenses_ap()
    test_findType()
    test_removeExpenses_ap()
    test_ReplaceExpense()
    test_overall_expense()
    test_NoApart()
    test_TotalExpense_type()
    test_findMaxE()
    test_NoApart2()
    test_NoApart3()
    l=[]
    while True:
        printMenu()
        cmd=input("Enter option:")
        if validCommand(cmd):
            if cmd=="0":
                break
            else:
                if cmd=="1":
                     tNew=readAtransaction()
                     while(tNew==-1):
                         print("give a valid transaction")
                         tNew=readAtransaction()
                         
                     ok=addAtransaction(l,tNew)
                     if(not ok):
                         print("the transaction exists")
                     else:
                         print("transaction added with success")
                         
                else:
                    if cmd=="2":
                        printMenu2()
                        cmd=input("Enter command: ")
                        if validCommand2(cmd):
                            if cmd=="0":
                                break
                            elif cmd=="1":
                                n=int(input("give apartment number:"))
                                if (findApartment(l,n)!=-1):
                                    while(findApartment(l,n)!=-1):
                                        removeExpenses_ap(l,n)
                                    print("the expenses were removed successfully")
                                else:
                                    print("No transactions for apartment 15 were found")
                            elif cmd=="2":
                                a=int(input("give first ap"))
                                b=int(input("give second ap"))
                                ok=0
                                      
                                for i in range (a,b+1):
                                    if(findApartment(l,i)!=-1):
                                        while(findApartment(l,i)!=-1):
                                            removeExpenses_ap(l,i)
                                            ok=1
                                        print("the expenses have been removed successfully")
                                if ok==0:
                                     print("there are no transactions for apartments 5 to 10")
                                    
                                       
                                        
                            elif cmd=="3":
                                tip=input("give type of expense to be removed:")
                                if(findType(l,tip)!=-1):
                                    while(findType(l,tip)!=-1):
                                        removeExpenses_type(l,tip)
                                        print("the expenses have been removed successfully")
                                else:
                                    print("there are no expenses for the given type")
                            elif cmd=="4":
                                ap=int(input("give ap number: "))
                    
                                tip=input("Give type of expense to be replaced: ")
                                su=float(input("give new expense: "))
                                if(ReplaceExpense(l,tip,ap,su)==True):
                                    print("The expense was replaced successfully")
                                else:
                                    print("There is no transaction in the list for apartment 12, having the indicated type")
                  
                       
                        else:
                            print("Enter a valid command")
                                        
                    elif cmd=="3":
                        printMenu3()
                        cmd=input("Enter option")
                        if(validCommand2(cmd)):
                            if(cmd=="1"):
                                l1=[]
                                for i in range(len(l)):
                                    t=l[i]
                                    n=float(input("Enter sum:"))
                                    if(overall_expense(l,t[2])>n):
                                        insertAp(l1,t[2])
                                printList(l1)       
                    
                            if(cmd=="2"):
                                l1=[]
                                ap=int(input("Before apartment:"))
                                n=float(input("Less than:"))
                                for i in range (0,len(l)):
                                        t=l[i]
                                        if(t[2]<ap and overall_expense(l,t[2])<n):
                                            insertAp(l1,t[2])
                                        printList(l1)
                                
                            if(cmd=="3"):
                                typ=input("give type:")
                                ExpType(l,typ)
                               
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
                                printMaxAp(l,ap)
                            if(cmd=="3"):
                                a=[]
                                ConstrListAp(l,a)
                                sort_asc(a)
                                print(a)
                                  
                            if(cmd=="4"):
                                a=[]
                                ConstrListTyp(l,a)
                                sort_desc(a)
                                print(a)
                        
                        else:
                            print("Enter a valid command")
                        
        else:
            print("Enter a valid command:")
        print(l)
main()
