'''
Created on 20 mar. 2016

@author: Pop Andra
'''
class Edge_Property:
    """
    Class Edge_Property contains a dictionary where:
    - keys - are pairs of type (x,y) - representing an edge
            -> x, y - integer numbers - representing vertices of a graph
    - value - cost - integer number - represents the cost of the edge (x,y)
    """
    def __init__ (self):
        """
        Constructor of class Edge_Property - initialize with an empty dictionary
        """
        self._edge ={}
        
    def getAll(self):
        """
        Getter of the edges
        Input: -
        Output: the dictionary containing the edges
        """
        return self._edge
    
    def Add(self, x,y,cost):
        """
        Adds a new property (cost) to the edge
        Input: x, y- natural numbers - the key of the edge
                cost - integer number - property added
        Output: - (Modifies the edge)
        Raises : KeyError if the edge (x,y) has already been added
        """
        if (x,y) in self._edge.keys():
            raise KeyError("This edge has already been added. ")
        self._edge[(x,y)]=cost
        
    def Update(self, x,y,cost):
        """
        Updates the property (cost) to the edge
        Input: x, y- natural numbers - the key of the edge
                cost - integer number - property updated
        Output: - (Modifies the edge)
        Raises : KeyError if the edge (x,y) doesn't exist
        """
        if (x,y) not in self._edge.keys():
            raise KeyError("This edge doesn't exist. ")
        self._edge[(x,y)]=cost

    def Remove(self, x,y):
        """
        Removes the edge (x,y) from the dictionary of edges
        Input: x, y- natural numbers - the key of the edge
        Output: - (Modifies the edge)
        Raises : KeyError if the edge (x,y) doesn't exist
        """
        if (x,y) not in self._edge.keys():
            raise KeyError("This edge doesn't exist. ")
        del self._edge[(x,y)]

    def getCost(self, x,y):
        """
        Getter of the cost of the edge (x,y)
        Input: x, y- natural numbers - the key of the edge
        Output:an integer number representing the cost
        Raises : KeyError if the edge (x,y) doesn't exist
        """
        if (x,y) not in self._edge.keys():
            raise KeyError("This edge doesn't exist. ")
        return self._edge[(x,y)]
      
    