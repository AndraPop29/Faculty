'''
Created on Mar 11, 2016

@author: Andra
'''
from Graph import *
from edgeProperty import *
class repo:
    def __init__(self,fName):
        self._graph=DDictGraph(0)
        self._ep=EP()
        self._f=fName
        self._copy=DDictGraph(0)
        self._loadFromFile()
        
    def _loadFromFile(self):
        """
        Opens the file and reads the data
        """
        f=open(self._f,"r")
        line=f.readline().strip().split()
        nrVertices=int(line[0])
        nrEdges=int(line[1])
      
        self._graph = DDictGraph(nrVertices)
      
    
        for x in range(nrEdges):
            line = f.readline().strip().split()
            startVertex = int(line[0])
            endVertex   = int(line[1])
            try:
                value = int(line[2])
            except:
                value = line[2]
            
            self._graph.addEdge(startVertex, endVertex)
           
            self._ep.addEP((startVertex, endVertex), value)
           
        f.close()
    
    def getVert(self):
        '''
        Getter for the number of vertices
        '''
        return self._graph._nrVertices
    
    def isEdge(self,x,y):
        '''
        Verifies if there is and edge from x to y
        Input:x,y-the vertices
        Post:Returns 1, if there is an edge
                Returns 0, otherwise
        '''
        if self.getOutD(x)!=-1: #in case the vertex x doesn't exist
            if(self._graph.isEdge(x, y)==True):
                return 1
        return 0
    def getEp(self,x,y):
        '''
        Getter for the edge property(cost)
        '''
        if self.isEdge(x, y):
            return self._ep.getEp(x,y)
        else:
            return -1
        
    def getAllEp(self):
        '''
        Getter for the edge property disctionary
        '''
        return self._ep.getAllEp()
    
    def modiCost(self,x,y,n):
        '''
        Modifies the cost attached to an edge
        Input:x,y-the extremeties
            n-the new cost
        Output:-
        '''
        self._ep.modiCost(x,y,n)
    
    def getInD(self,x):
        '''
        Getter for the in degree of a certain vertex
        '''
        s=0
        ok=0
        for i in self._graph._dictIn:
            if i==x:
                ok=1
                for j in self._graph._dictIn[i]:
                    s=s+1;
        if ok==0:
            return -1
        return s
        
    
    def getOutD(self,x):
        '''
        Getter for the out degree of a certain vertex
        '''
        s=0
        ok=0
        for i in self._graph._dictOut:
            if i==x:
                ok=1
                for j in self._graph._dictOut[i]:
                    s=s+1;
        if ok==0:
            return -1
        return s
    
    def getOutL(self,x):
        '''
        Getter for the list of out bound edges of a certain vertex
        '''
        for i in self._graph._dictOut:
            if i==x:
                return self._graph._dictOut[i]
        return []
            
    def getInL(self,x):
        '''
        getter for the list of in bound edges of a certain vertex
        '''
        for i in self._graph._dictIn:
            if i==x:
                return self._graph._dictIn[i]
        return []
    
    def addVertex(self):
        '''
        Adds a vertex to the graph
        '''
        self._graph._dictIn[self._graph._nrVertices]=[]
        self._graph._dictOut[self._graph._nrVertices]=[]
       
        self._graph._nrVertices=self._graph._nrVertices+1
    
    def removeAllEdges(self,l,x):
        '''
        Removes the edges stored in a distionary, that contain a specified vertex
        Input:l-the dictionary, x-the vertex
        Output:-
        '''
        for i in l:
            j=0
            
            while j<len(l[i]):
                if l[i][j]==x:
                    print(l[i][j])
                    l[i].pop(j)
                    self._ep.removeEP(x,i)
                    self._ep.removeEP(i,x)
                    
                else:
                    j=j+1   
    def removeKey(self,x,l):
        '''
        Removes a vertex(key) from a dictionary
        Input:x-the vertex, l-the dictionary
        Output:-
        Post:1, if successful
            0, if the key doesn't exist
        '''
        for i in l:
            if i==x:
                j=0;
                while j<len(l[i]):
                    self._ep.removeEP(i, l[i][j])
                    j=j+1

                l.pop(i)
                return 1
        return 0
    def removeVertex(self,x):
        '''
        Removes a vertex from the graph
        Input:x-the vertex number
        Output:Returns 1, if successful
            Returns 0, otherwise
        '''
        val=self.removeKey(x,self._graph._dictOut)
        val2=self.removeKey(x, self._graph._dictIn)
        if val==0 and val2==0:
            return 0;
        self.removeAllEdges(self._graph._dictOut,x)
        self.removeAllEdges(self._graph._dictIn,x)
        self._graph._nrVertices=self._graph._nrVertices-1
        return 1
    def getGraph(self):
        '''
        Getter for the graph
        '''
        return self._graph
    
    def addEdge(self,x,y,c):
        '''
        Adds an edge to the graph, along with its cost
        Input:x,y-the extremities, c-the cost
        Output:-
        '''
        self._ep.addEP((x,y), c)
        return self._graph.addEdge(x,y)
    
    def getPos(self,x,l):
        '''
        Getter for the position of a certain vertex in a dictionry
        Input:x-the vertex, l-the dictionary
        Output:i, the position
            -1, if the vertex doesn't exist
        '''
        i=0
        while i<len(l):
            if l[i]==x:
                return i
            else:
                i=i+1
        return -1
    def removeEdge(self,x,y):
        '''
        Removes the edge from x to y and its cost
        Input:x-y-vertices
        Output:0,if no such edge
            1, otherwise
        '''
        ase=x in self._graph._dictIn.keys()
        ase2=y in self._graph._dictIn.keys()
        if(ase==False or ase2==False): #or (y in self._graph._dictIn.keys()==False)):
            return 0
        pos=self.getPos(y,self._graph._dictOut[x])
        
        pos1=self.getPos(x,self._graph._dictIn[y])
        if pos==-1 and pos1==-1:
            return 0
        self._graph._dictOut[x].pop(pos)
        self._graph._dictIn[y].pop(pos1)
        self._ep.removeEP(x, y)
        return 1
    def makeCopy(self):
        '''
        Makes a copy of the double dictionary graph
        '''
        self._copy=DDictGraph(self._graph.getNrVertices())
        for i in range(self._copy._nrVertices):
            self._copy._dictOut[i]=self._graph._dictOut[i]
            self._copy._dictIn[i] = self._graph._dictIn[i]
        
    def getCopy(self):
        '''
        Getter for the copy
        '''
        return self._copy
        
