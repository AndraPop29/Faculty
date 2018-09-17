'''
Created on 7 mar. 2016

@author: Pop Andra
'''

class Directed_Graph:
    """
    Class Directed_Graph contains :
    dictOut - dictionary, where key: the origin vertex
                               value: all the target vertices associated to the key
    dictIn - dictionary, where key: the target vertices
                                value: all the origin vertices associated to the key
    """
   
    def __init__(self, n):
        """
        Constructor of a directed graph with n vertices and no edges
        Input: n ( natural number ) - no. of vertices
        """
        self.__dictOut = {}
        self.__dictIn = {}
        for i in range(n):
            self.__dictOut[i] = []
            self.__dictIn[i] = []
            
    def getVertices (self):
        """
        Getter of all the vertices in this graph
        Input: -
        Output: a list of vertices
        """
        return self.__dictOut.keys()
    
    def isEdge(self, x, y):
        """
        Checks if there is an edge between x and y
        Input: x - origin vertex
               y - target vertex
        Output: True, if there exists an edge from x to y
                False, otherwise
        Raises : KeyError if x or y is not a vertex of this graph
        """
        if x not in self.getVertices() or y not in self.getVertices():
            raise KeyError(" There is at least one vertex that does not belong to the graph ")
        else :
            return y in self.__dictOut[x]
        
    def iterateOut(self, x):
        """
        Iterate through the set of out-bound edges of a specified vertex
        Input: x- natural number - the specified vertex
        Output: A list of the vertices containing  x as out-bound vertex 
        Raises : KeyError if the vertex x is not in the graph
        """
        if x not in self.getVertices():
            raise KeyError (" This vertex in not in the graph :(")
        return self.__dictOut[x]
   
    def iterateIn(self, x):
        """
        Iterate through the set of in-bound edges of a specified vertex
        Input: x- natural number - the specified vertex
        Output: A list of the vertices containing  x as in-bound vertex 
        Raises : KeyError if the vertex x is not in the graph
        """
        if x not in self.getVertices():
            raise KeyError (" This vertex in not in the graph :(")
        return self.__dictIn[x] #return all the target 
    
   
    def addEdge(self, x, y):
        """
        Adds an edge between two vertices and increase the number of edges
        Input: x - the origin vertex
               y - the target vertex
        Output: - (Modifies the dictionaries from the graph)
        Raises: KeyError if this edge already exists
                KeyError if x or y are not vertices of the graph
        """
        #might raise KeyError if x or y are not vertices
        isEdge=self.isEdge(x, y) 
        if isEdge==True:
            raise KeyError("This is already an edge of the graph. ")
        #otherwise we add it
        self.__dictIn[y].append(x)
        self.__dictOut[x].append(y)
         
    def removeEdge(self, x, y):
        """
        Removes an edge
        Input: x - the origin vertex
               y - the target vertex
        Output: - (Modifies the dictionaries from the graph)
        Raises: KeyError if this edge doesn't exist
                KeyError if x or y are not vertices of the graph
        """
        #might raise KeyError if x or y are not vertices
        isEdge=self.isEdge(x, y) 
        if isEdge==False :
            raise KeyError(" This is already an edge of the graph. ")
        #otherwise we remove it
        self.__dictIn[y].remove(x)
        self.__dictOut[x].remove(y)
    
    def addVertex(self, vertex):
        """
        Adds a vertex to the graph
        Input: vertex (natural number )
        Output: - (modifies the graph)
        Raises: KeyError if 'vertex' is already a vertex
        """
        if vertex in self.getVertices():
            raise KeyError (" This vertex already exists :(")
        #Otherwise add the vertex
        self.__dictIn[vertex]=[]
        self.__dictOut[vertex]=[]
        
    def removeVertex(self, vertex):
        """
        Removes a vertex from the graph
        Input: vertex( natural number )
        Output: - (modifies the graph)
        Raises: KeyError if 'vertex' does not belong to the graph
        """
        if vertex not in self.getVertices():
            raise KeyError (" This vertex doesn't exist in the graph :(")
        
        #Otherwise remove the vertex - from dictIn and dictOut
        while len(self.__dictIn[vertex])!=0:
            origin=self.__dictIn[vertex][0]
            self.removeEdge(origin, vertex)
        while len(self.__dictOut[vertex])!=0:
            target=self.__dictOut[vertex][0]
            self.removeEdge(vertex, target)
            
        #Delete the key 'vertex' from each dictionary
        del self.__dictOut[vertex]
        del self.__dictIn[vertex]   
        
    def inDegree(self, vertex):
        """
        Getter of the in-degree of a specified vertex
        Input: vertex- natural number - the specified vertex
        Output: a natural number
        Raises : KeyError if the vertex  is not in the graph
        """
        return len(self.iterateIn(vertex))
   
    def outDegree(self, vertex):
        """
        Getter of the out-degree of a specified vertex
        Input: vertex- natural number - the specified vertex
        Output: a natural number
        Raises : KeyError if the vertex  is not in the graph
        """
        return len(self.iterateOut(vertex))
    
    def accessible(self, s):
        """
        Returns the set of vertices of the graph  that are accessible
        from the vertex s
        """
        acc = set()
        acc.add(s)
        alist = [s]
        while len(alist) > 0:
            x = alist[0]
            alist = alist[1 : ]
            for y in self.parseNout(x):
                if y not in acc:
                    acc.add(y)
                    alist.append(y)
        return acc
    
   