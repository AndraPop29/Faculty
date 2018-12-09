'''
Created on Mar 11, 2016

@author: Andra
'''
class DDictGraph:
    """A directed graph, represented as two maps,
    one from each vertex to the set of outbound neighbours,
    the other from each vertex to the set of inbound neighbours"""

    def __init__(self,n):
        """Creates a graph with n vertices (numbered from 0 to n-1)
        and no edges"""
        self._dictOut={}
        self._dictIn = {}
        self._nrVertices=n
        for i in range(n):
            self._dictOut[i]=[]
            self._dictIn[i] = []
    
    def isVert(self,x):
        '''
        verifies if x is a vertex in the graph
        Input:x-the vertex
        Output:1,if true
               0,if false
        '''   
        return x in self._dictIn.keys()        
    def parseX(self):
        """Returns an iterable containing all the vertices"""
        return self._dictOut.keys()

    def parseNout(self,x):
        """Returns an iterable containing the outbound neighbours of x"""
        return self._dictOut[x]

    def parseNin(self,x):
        """Returns an iterable containing the inbound neighbours of x"""
        return self._dictIn[x]    

    def isEdge(self,x,y):
        """Returns True if there is an edge from x to y, False otherwise"""
        #if self._dictOut[x]:
        return y in self._dictOut[x]
        

    def addEdge(self,x,y):
        """Adds an edge from x to y.
        Precondition: there is no edge from x to y"""
        v=x in self._dictIn.keys()
        v1=y in self._dictIn.keys()
       
       
        if (v==True and v1==True):
           
            v2=self.isEdge(x,y)
            if(v2==False):
                self._dictOut[x].append(y)
                self._dictIn[y].append(x)
            
                return 1
        else:
            return 0
        
    def getNrVertices(self):
        return self._nrVertices
                