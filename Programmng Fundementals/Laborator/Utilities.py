
def InitialTest(l):
    l.append([100.5,'water',14])
    l.append([93.9, 'gas', 15])
    l.append([20, 'illuminating', 3])
    
#For the first iteration
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

#Iteration 2.1 and 2.2
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

#Iteration 2.3
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
    
#Iteration 2.4
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

#Iteration 3.1 and 3.2

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
def insertAp(l,ap):
    '''
    Description: inserts the apartment in the new list if it doesn't exist
    Input:l,ap
    Prec:l-list of apartments, ap-apartment number
    Output: -
    Post:-
    '''
    if(NoApart(l,ap)==True):
        l.append(ap)
        return True
    else:
        return False
def test_insertAp():
    l=[12,4,9,5]
    assert insertAp(l,5)==False
    assert insertAp(l,13)==True


#Iteration 3.3
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
                return t
    return -1
    
def test_ExpType():
    l=[[12.5,'water',100],[3,'gas',90]]
    assert ExpType(l,'water')==[12.5,'water',100]
    assert ExpType(l,'illuminating')==-1
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
def MaxAp(l,ap):
    '''
    Description: Prints the maximum expense for an apartment, if it is in the list
    Input:l,ap
    Prec:l-list of transactions
         ap-apartment number
    Output:-
    Post:-

    '''
    typ=findMaxE(l,ap)
    return typ
def test_MaxAp():
    l=[[12,'water',15],[58.8,'gas',15],[90,'water',8]]
    assert MaxAp(l,15)=='gas'
    assert MaxAp(l,1)=='null'

#Iteration 4.3
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
    if(len(l)==0):
       
        return -1
    for i in range(0,len(l)):
        t=l[i]
        ex=overall_expense(l,t[2])
        if NoApart2(a,t[2]):
            a.append([ex,t[2]])
def test_ConstrList():
    l=[]
    a=[]
    assert ConstrList(l,a)==-1
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
#Iteration 4.4
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
    if(len(l)==0):
        return -1
    for i in range(0,len(l)):
        t=l[i]
        ex=TotalExpense_type(l,t[1])
        if NoApart3(a,t[1]):
            a.append([ex,t[1]])
def test_ConstrListTyp():
    l=[]
    a=[]
    assert ConstrListTyp(l,a)==-1
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
#Iteration 5.1
def FilterType(l,typ):
    """
    Specification: Removes all of the expenses that don't have the given type
    Input:l,typ
    Prec: l-list of transactions, typ-type of the expense that we are filtering
    Output:-
    Post:-
    """
    i=0
    while(i<len(l)):
        t=l[i]
        if(t[1]!=typ):
            removeExpenses_type(l,t[1])
        else:
            i=i+1
def test_FilterType():
    l=[[21,'water',5],[39,'gas',9]]
    FilterType(l,'water')
    assert l==[[21,'water',5]]
    FilterType(l,'illuminating')
    assert l==[[21,'water',5],[39,'gas',9]]
#Iteration 5.2   
def FilterSum(a,s):
    """
    Description: Removes all of the overall expenses that are less than the given sum
    Input: a,s
    Prec: a-list of overall expenses, s-sum
    Output:-
    Post:-
    """
    ainitial=a
    
    i=0
    while(i<len(a)):
        t=a[i]
        if(t[0]<s):
            a.pop(i)
        else:    
            i=i+1
    if (a==ainitial):
        return -1
def test_FilterSum():
    l=[[21,5],[39,9]]
    FilterSum(l,30)
    assert l==[[39,9]]
    assert FilterSum(l,40)==-1
            
    test_verifyExistance()
    test_addAtransaction()
    test_findApartment()
    test_removeExpenses_ap()
    test_findType()
    test_removeExpenses_ap()
    test_ReplaceExpense()
    test_overall_expense()
    test_NoApart()
    test_insertAp()
    test_ExpType()
    test_TotalExpense_type()
    test_findMaxE()
    test_printMaxAp()
    test_NoApart2()
    test_ConstrList()
    test_NoApart3()
    test_ConstrListTyp()
    test_FilterType()
    test_FlterSum()
    
