'''
Created on Mar 11, 2016

@author: Andra
'''
class EP:
    def __init__(self):
        self._ep={}
        
    
    
    def addEP(self,epKey,epCost):
        '''
        Adds an edge property
        Input: key, cost
        Output:-
        '''
        epCost=int(epCost)
        self._ep[epKey]=epCost
    
        
    def getEp(self,x,y):
        '''
        Getter for the edge property of a certain edge
        '''
        epKey=(x,y)
        return self._ep[epKey]
    
    def modiCost(self,x,y,n):
        '''
        Modifies the cost of a certain edge
        Input:key, new cost
        '''
        epKey=(x,y)
        self._ep[epKey]=n
    
    def epExists(self,key):
        '''
        Verifies if a key exists
        Input:key
        Output:1, if it exists
               0,otherwise
        '''
        if key in self._ep:
            return 1
        return 0
    def removeEP(self,i,j):
        '''
        Removes a key(edge)
        Input:i,j-extremities
        Output:-
        '''
        key=(i,j)
        if(self.epExists(key)):
            self._ep.pop(key) 
    def getAllEp(self):
        '''
        Getter for the edge properties
        '''
        return self._ep