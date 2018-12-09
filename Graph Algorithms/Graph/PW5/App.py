'''
Created on May 23, 2016

@author: Radu
'''
from UnGraph.UnGraph import *

aUnGraph=unGraph("undirected.txt")
#print("The adjacency matrix is: ")
#aUnGraph.printMatrix()

print(aUnGraph.hamCycle())