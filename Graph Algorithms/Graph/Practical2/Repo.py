'''
Created on Mar 11, 2016

@author: Andra
'''
from Graph import *
from edgeProperty import *
from macpath import pathsep
from queue import PriorityQueue

class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0,item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)
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
    
    def addVertex(self,x):
        '''
        Adds a vertex to the graph
        '''
        #self._graph._dictIn[self._graph._nrVertices]=[]
        #self._graph._dictOut[self._graph._nrVertices]=[]
        if(self._graph.isVert(x)==False):
            self._graph._dictIn[x]=[]
            self._graph._dictOut[x]=[]
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
        for i in self._graph._dictOut.keys():
            self._copy._dictOut[i]=self._graph._dictOut[i]
            self._copy._dictIn[i] = self._graph._dictIn[i]
        
    def getCopy(self):
        '''
        Getter for the copy
        '''
        return self._copy
        
    #def DAG(self):
        #for i in self._graph._
        '''
        Given a directed acyclic graph, do a topological sort on this graph.
 *
 *     Do DFS by keeping visited. Put the vertex which are completely explored into a stack.
 *     Pop from stack to get sorted order.
 *
 *     Space and time complexity is O(n).
         '''
    def topSort(self):
        stack=[];
        visited=[];
        for i in self._graph._dictIn.keys():
            #print(i);
            if i not in visited:
                #continue;
                self.topSortUtil(i,stack,visited);
        return(stack[::-1])
    def topSortUtil(self,i,stack,visited):
        visited.append(i);
        #print(i);
        for j in self.getOutL(i):
            #print()
            if j not in visited:
                #continue;
                self.topSortUtil(j,stack,visited);
        #print(i);
        stack.append(i);
        '''
    Input:
    G : directed graph
Output:
    sorted : a list of vertices in topological sorting order, or null if G has cycles
    '''
    def topoSort(self):
        sorted = []
        q=Queue()
        count={}
        for x in self._graph._dictIn.keys():
            count[x] = self.getInD(x)
            if count[x] == 0:
                q.enqueue(x)
        
    
        while not q.isEmpty():
            x = q.dequeue()
            
            sorted.append(x)
            for y in self.getOutL(x):
                count[y] = count[y] - 1
                if count[y] == 0:
                    q.enqueue(y)
        if len(sorted) < self._graph._nrVertices:
            sorted = []
        return sorted
    
    def DAG(self):
        t=self.topoSort();
        if t==[]:
            return "Not a DAG"
        return "Yes it is"
        '''
        for i in range(0,len(t)-1):
            
            for j in range(i+1,len(t)):
                if j in self.getInL(i):
                    #print(j,self.getInL(i));
                    return "Not a DAG!";
        return "Is a DAG";
        '''
        '''
        for i in self._graph._dictIn.keys():
            
            if len(self.bfs_backward(i,i))!=1:
                
                return "The graph is not a DAG";
            print(i,self.bfs_backward(i,i));
        return "The graph is a DAG";
        '''    
    def longestPath(self,a,b):
        t=self.topSort();
        d={}
        for i in self._graph.parseX():
            d[i]=0
        for x in t:
            value=0
            for y in self.getInL(x):
                if d[y]+self._ep.getEp(y,x)>value:
                    value=d[y]+self._ep.getEp(y,x)
            d[x]=value
        path=[]
        while d[b] > 0:
            path.append(b)
            for i in self.getInL(b):
                if d[i]+self._ep.getEp(i,b)==d[b]:
                    #print(a,b)
                    b=i
                    break
        path.append(b)
        #path.reverse()
        
        
        for i in d.keys():
            print("Key: ",i,"Value: ",d[i]);
        return path
        
        
    def maxCostPath(self,s,t):
        q=PriorityQueue()#ordered on priority
        prev={}#each accessible vertex : its predecessor on a path from s to it
        dist={}#each accessibe vertex:the cost of the minimum walk
        q.put(s,0)#put the element s in the queue
        dist[s]=0#distance from s to s=0
        path=[]#the initial path
        while not q.empty():
            x=q.get()#gets the last element from the priority queue
            #print(q[:])
            #print("first: ",x);
            #print("prev: ",prev, "  x: ", x)
            #print("dist: ",dist)
            for y in self.getOutL(x):
                #print (" x: ",x,"  y: ",y, "  cost: ", self.get_cost(x, y))
                if y not in dist.keys() or dist[x]+ self._ep.getEp(x, y) > dist[y]:
                    dist[y]=dist[x]+self._ep.getEp(x, y)
                    q.put(y,dist[y])
                    prev[y]=x
        if t in dist:
            print("Maximum cost:",dist[t])
            path.append(t)
            end=t
            while end in prev:
                #print("end: ", end)
                #print("prev: ",prev)
                pr=prev[end]
                path.append(pr)
                end=pr
            path.reverse()
            print("The path of maximum cost: ",path) 
        else:
            print("No path ")        
    def bfs_backward(self,start,end):
        '''
        Write a program that, given a directed graph and two vertices, 
        finds a lowest length path between them, 
        by using a backward breadth-first search from the ending vertex.
        '''
        if self._graph.isVert(start)==False or self._graph.isVert(end)==False:
            return "One or both vertices don't exist"
        queue=[]#queue of pathsep
        visited=[]
        #add the first node(end)
        queue.append([end])
        while queue:
            #print("Queue ",queue)
            #take the first vertex from the queue and the last vertex from the current Path
            path=queue.pop(0)
            print(path)
            node=path[-1]
            
            print ("Node ",node)
            if node not in visited:
                #print("Path: ",path,"    Length path  " , len(path))
                # if we found the path we return it
                if node==start:
                    return(path[::-1])#returns the reversed list
                #print("In-bound: ", self.getInL(node))
                # add all adjacent vertices in the queue 
                for adjacent in self.getInL(node):
                    new_path=list(path)
                    new_path.append(adjacent)
                    queue.append(new_path)
                #print("Queue: ",queue)
        return "There is no path"
    '''
    def DFS_util(self,x,visited,stack):
        visited.append(x)
        for y in self.getOutL(x):
            if y not in visited:
                self.DFS_util(y,visited,stack)
        print(stack)
        stack.append(x)
    def DFS(self):
        visited=[]
        stack=[]
        for x in self._graph._dictOut.keys():
            if x not in visited:
                print("In main: ",x)
                self.DFS_util(x, visited, stack)
    '''      
        