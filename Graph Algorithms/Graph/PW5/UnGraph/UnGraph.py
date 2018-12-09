'''
Created on May 23, 2016

@author: Andra
'''

class unGraph:
    def __init__(self,fName):
        self._f=fName
        self._graph=[]
        self._nrVertices=0
        self._nrEdges=0
        self._loadFromFile()
        
    def _loadFromFile(self):
        """
        Opens the file and reads the data
        """
        f=open(self._f,"r")
        line=f.readline().strip().split()
        self._nrVertices=int(line[0])
        self._nrEdges=int(line[1])
      
        #self._graph = DDictGraph(nrVertices)
      
        for i in range (self._nrVertices):
            self._graph.append([])
            for j in range (self._nrVertices):
                self._graph[i].append(0)
        for x in range(self._nrEdges):
            line = f.readline().strip().split()
            startVertex = int(line[0])
            endVertex   = int(line[1])
            self._graph[startVertex][endVertex]=1
            
            
           
        f.close()

    def printMatrix(self):
        for i in range(0,self._nrVertices):
            for j in range (0,self._nrVertices):
                print(self._graph[i][j])
    def isOk(self,v,path,pos):
        if self._graph[path[pos-1]][v]==0:#verificam daca exista muchie intre cele 2 noduri
            return False
        for i in range (pos):
            if path[i]==v:#daca nodul se afla deja in ciclu
                return False
        return True
        
    def hamCycleUtil(self,path,pos):
        if pos==self._nrVertices:#se opreste in momentul in care ajungem la ultimul varf
            if(self._graph[path[pos-1]][path[0]]==1):
                return True
            else:
                return False
        
        for v in range (self._nrVertices):
            if(self.isOk(v,path,pos)):
                path.append(v)
                if(self.hamCycleUtil(path,pos+1)==True):#functie recursiva pentru urmatorul nod
                    return True;
        return False
        
    def hamCycle(self):
        path=[]
        #for i in range (0,self._nrVertices-1):
            #path.append(-1)
        path.append(0)
        if ( self.hamCycleUtil(path, 1) == False ):
    
            print("Solution does not exist");
            return False;
    
 
        #printSolution(path);
        print("The hamiltonian cycle is: ")
        return path;