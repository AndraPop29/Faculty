'''
Created on Mar 11, 2016

@author: Andra
'''
from Repo import *
class controller:
    def __init__(self,repo):
        self._repo=repo
    
    def getVert(self):
        '''
        Getter for the number of vertices
        '''
        return self._repo.getVert()
    
    def isEdge(self,x,y):
        '''
        Verifies if there is and edge from x to y
        Input:x,y-the vertices
        Post:Returns 1, if there is an edge
                Returns 0, otherwise
        '''
        return self._repo.isEdge(x,y)
    
    def getEp(self,x,y):
        '''
        Getter for the edge property(cost)
        '''
        return self._repo.getEp(x,y)
        
    def getInD(self,x):
        '''
        Getter for the in degree of a certain vertex
        '''
        return self._repo.getInD(x)
    
    def getOutD(self,x):
        '''
        Getter for the out degree of a certain vertex
        '''
        return self._repo.getOutD(x)
    
    def getOutL(self,x):
        '''
        Getter for the list of out bound edges of a certain vertex
        '''
        return self._repo.getOutL(x)
    
    def getInL(self,x):
        '''
        Getter for the list of in bound edges of a certain vertex
        '''
        return self._repo.getInL(x)
    
    def modiCost(self,x,y,n):
        '''
        Modifies the cost attached to an edge
        Input:x,y-the extremeties
            n-the new cost
        Output:-
        '''
        self._repo.modiCost(x,y,n)
        
    def getGraph(self):
        '''
        Getter for the graph
        '''
        return self._repo.getGraph()
    
    def addVertex(self):
        '''
        Adds a vertex to the graph
        '''
        self._repo.addVertex()
    def removeVertex(self,x):
        '''
        Removes a vertex from the graph
        Input:x-the vertex number
        Output:Returns 1, if successful
            Returns 0, otherwise
        '''
        if self._repo.removeVertex(x)==0:
            return "The vertex doesn't exist"
        else:
            return "The vertex has been removed"
    
    def addEdge(self,x,y,c):
        '''
        Adds an edge to the graph, along with its cost
        Input:x,y-the extremities, c-the cost
        Output:-
        '''
        if(self._repo.addEdge(x,y,c)==0):
            return "Not possible"
        else:
            return "The edge has been added"
        
    def removeEdge(self,x,y):
        '''
        Removes the edge from x to y and its cost
        Input:x-y-vertices
        Output:0,if no sch edge
            1, otherwise
        '''
        if(self._repo.removeEdge(x, y)==0):
            return "That edge does not exist"
        else:
            return "Edge has been removed"
    
    def makeCopy(self):
        '''
        Makes a copy of the double dictionary graph
        '''
        self._repo.makeCopy()
        
    def getCopy(self):
        '''
        Getter for the copy
        '''
        return self._repo.getCopy()
    
    def getAllEp(self):
        '''
        Getter for the EP graph
        '''
        return self._repo.getAllEp()