'''
Created on 20 mar. 2016

@author: Pop Andra
'''

from domain.DirectedGraphs import *
from domain.EdgeProperty import *
from queue import PriorityQueue

class Graph_Controller: 
    """
    Class Graph_Controller makes the link between Directed_Graph
    and Edge_Property such that all the changes that are made cover
    both objects.
    """
    
    def __init__ (self, name_file):
        """
        Constructor of Graph_Controller Class 
        name_file - the file from which we read the graph
        """
        self._fileName= name_file
        self.readFromFile()
        
    def dijkstra_fw(self,s,t):
        q=PriorityQueue()#ordered on priority
        prev={}#each accessible vertex : its predecessor on a path from s to it
        dist={}#each accessibe vertex:the cost of the minimum walk
        q.put(s,0)#put the element s in the queue
        dist[s]=0#distance from s to s=0
        path=[]#the initial path
        while not q.empty():
            x=q.get()#gets the last element from the priority queue
            #print(q[:])
            print("first: ",x);
            #print("prev: ",prev, "  x: ", x)
            #print("dist: ",dist)
            for y in self.iterate_outbound(x):
                #print (" x: ",x,"  y: ",y, "  cost: ", self.get_cost(x, y))
                if y not in dist.keys() or dist[x]+ self.get_cost(x, y) < dist[y]:
                    dist[y]=dist[x]+self.get_cost(x, y)
                    q.put(y,dist[y])
                    prev[y]=x
        if t in dist:
            print("Minimum cost:",dist[t])
            path.append(t)
            end=t
            while end in prev:
                #print("end: ", end)
                #print("prev: ",prev)
                pr=prev[end]
                path.append(pr)
                end=pr
            path.reverse()
            print("The path of minimum cost: ",path) 
        else:
            print("No path ")
            

    
        
    def readFromFile(self):
        """
        Reads the graph from the file and constructs both classes
        """
        f=open(self._fileName, "r")
        line=f.readline().strip().split(' ')
        n= int(line[0])
        m=int(line[1])
        self._graph=Directed_Graph(n)
        self._edge=Edge_Property()
        for i in range (0,m):
            line=f.readline().split(' ')
            x=int(line[0])
            y=int(line[1])
            cost=int(line[2])
            self.add_edge(x,y,cost)
        f.close()
            
    def get_vertices(self):
        """
        Getter of all the vertices in this graph
        Input: -
        Output: a list of vertices
        """
        return self._graph.getVertices()
    
    def get_vertices_no(self):
        """
        Getter of the number of the vertices in this graph
        Input: -
        Output: a natural number
        """
        return len(self._graph.getVertices())
    
    def get_edges(self):
        """
        Getter of all the edges in this graph
        Input: -
        Output: a dictionary of edges
        """
        return self._edge.getAll()
        
    def get_edges_no(self):
        """
        Getter of the number of the edges in this graph
        Input: -
        Output: a natural number
        """
        return len(self._edge.getAll())  
      
    def get_in_degree (self, x):
        """
        Getter of the in-degree of a specified vertex
        Input: x- natural number - the specified vertex
        Output: a natural number
        Raises : KeyError if the vertex  is not in the graph
        """
        return self._graph.inDegree(x)
    
    def get_out_degree (self, x):
        """
        Getter of the out-degree of a specified vertex
        Input: vertex- natural number - the specified vertex
        Output: a natural number
        Raises : KeyError if the vertex  is not in the graph
        """
        return self._graph.outDegree(x)
    
    def iterate_outbound(self, x):
        """
        Iterate through the set of out-bound edges of a specified vertex
        Input: x- natural number - the specified vertex
        Output: A list of the vertices containing  x as out-bound vertex 
        Raises : KeyError if the vertex x is not in the graph
        """
        return self._graph.iterateOut(x)
    
    def iterate_inbound(self, x):
        """
        Iterate through the set of in-bound edges of a specified vertex
        Input: x- natural number - the specified vertex
        Output: A list of the vertices containing  x as in-bound vertex 
        Raises : KeyError if the vertex x is not in the graph
        """
        return self._graph.iterateIn(x)
    
    def is_edge(self, x, y):
        """
        Checks if there is an edge between x and y
        Input: x - origin vertex
               y - target vertex
        Output: True, if there exists an edge from x to y
                False, otherwise
        Raises : KeyError if x or y is not a vertex of this graph
        """
        return self._graph.isEdge(x, y)

    
    def add_edge(self, x, y, cost):
        """
        Adds an edge between two vertices and increase the number of edges
        Input: x - natural number - the origin vertex 
               y - natural number - the target vertex
               cost - integer number - property added
        Output: - (Modifies the dictionaries from the graph)
        Raises: KeyError if this edge already exists
                KeyError if x or y are not vertices of the graph
        """
        self._graph.addEdge(x, y)
        self._edge.Add(x, y, cost)
        
    def remove_edge(self, x, y):
        """
        Removes an edge
        Input: x - the origin vertex
               y - the target vertex
        Output: - (Modifies the dictionaries from the graph)
        Raises: KeyError if this edge doesn't exist
                KeyError if x or y are not vertices of the graph
        """
        self._graph.removeEdge(x, y)
        self._edge.Remove(x, y)
        
    def update_cost(self, x, y, cost):
        """
        Updates the property (cost) to the edge
        Input: x, y- natural numbers - the key of the edge
                cost - integer number - property updated
        Output: - (Modifies the edge)
        Raises : KeyError if the edge (x,y) doesn't exist
        """
        self._edge.Update(x, y, cost)
        
        
    def add_vertex(self, x):
        """
        Adds a vertex to the graph
        Input: x (natural number )
        Output: - (modifies the graph)
        Raises: KeyError if the vertex 'x' is already a vertex
        """
        self._graph.addVertex(x)
        
    def remove_vertex(self, x):
        """
        Removes a vertex from the graph
        Input: vertex( natural number )
        Output: - (modifies the graph)
        Raises: KeyError if 'vertex' does not belong to the graph
        """
        self._graph.removeVertex(x)
        edges_deleted = []
        for (i,j) in self._edge.getAll():
            if i == x or j == x:
                edges_deleted.append((i, j))
        for (i,j) in edges_deleted:
            self._edge.Remove(i, j)
    
    def get_cost(self, x, y):
        """
        Getter of the cost of the edge (x,y)
        Input: x, y- natural numbers - the key of the edge
        Output: an integer number representing the cost
        Raises : KeyError if the edge (x,y) doesn't exist
        """
        return self._edge.getCost(x, y)
    
    def bfs_forward(self, start, end):
        return self._graph.bfs(start, end)
    
    #0-99,1-199,1-27,2-333,10-27
    
    