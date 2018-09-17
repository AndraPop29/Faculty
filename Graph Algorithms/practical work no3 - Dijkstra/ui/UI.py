'''
Created on 7 mar. 2016

@author: Pop Andra
'''
from Controller.GraphController import Graph_Controller

class Ui:
    """
    The user interface class - links the controller to the main application
    """
    
    def __init__(self, Graph_Controller):
        """
        Constructor of the class Ui
        """
        self._ctrl= Graph_Controller

    def print_menu(self):
        """
        Prints the menu of the program
        """
        s = "\n Choose  from the following options:\n"
        s += "menu - to print again the menu\n"
        s += "walk_f - find a lowest cost walk between 2 given vertices, using a forward Dijkstra algorithm \n"
        s += "1 - Get number of vertices\n"
        s += "2 - Find if an edge belongs to the graph\n"
        s += "3 - Get the in and the out degree of a vertex\n"
        s += "4 - Iterate in-bound edges of a vertex\n"
        s += "5 - Iterate out-bound edges of a vertex\n"
        s += "6 - Get the cost of an edge\n"
        s += "7 - Add a vertex to the graph\n"
        s += "8 - Remove a vertex from the graph\n"
        s += "9 - Add an edge to the graph\n"
        s += "10 - Remove an edge from the graph\n"
        s += "11 - Update an edge\n"
        s += "12 - Print the graph - in-bound and out-bound \n"
        s += "13 - Print graph like in file with isolated vertices \n"
        s += "14 - Print graph like in file \n"
        s += "0 - Exit\n"
        print (s)
        
    def main_menu (self):
        keepAlive= True
        self.print_menu()
        while keepAlive==True :
            cmd=input("Give your command: ").strip()
            try:
                if cmd =='menu':
                    # menu - print again the menu
                    self.print_menu()
                    
                elif cmd =='walk':
                    # walk - find a lowest cost walk between 2 given vertices, using a backwards Dijkstra algorithm
                    vertex_1= int(input("Give starting vertex: "))
                    vertex_2= int(input("Give ending vertex: "))
                    ok=True
                    if(vertex_1 not in self._ctrl.get_vertices()):
                        print ("starting vertex is not a vertex of the graph")
                        ok=False
                    if(vertex_2 not in self._ctrl.get_vertices()):
                        print ("target vertex is not a vertex of the graph")
                        ok=False
                    if (ok==True):
                        self._ctrl.dijkstra_bk(vertex_1, vertex_2)
                    
                elif cmd =='walk_f':
                    # walk - find a lowest cost walk between 2 given vertices, using a backwards Dijkstra algorithm
                    vertex_1= int(input("Give starting vertex: "))
                    vertex_2= int(input("Give ending vertex: "))
                    self._ctrl.dijkstra_fw(vertex_1, vertex_2)                 
                elif cmd=='1':
                    #1-get the number of vertices
                    print("The number of vertices is",self._ctrl.get_vertices_no())
                
                elif cmd =='2':
                    #2-find if an edge belongs to the graph
                    vertex_1= int(input("Give first vertex: "))
                    vertex_2= int(input("Give second vertex: "))
                    if self._ctrl.is_edge(vertex_1, vertex_2)==True:
                        print (" It is an edge ")
                    else:
                        print(" Not an edge ")
                
                elif cmd =='3':
                    #3- get the in and the out degree of a vertex
                    vertex= int(input("Give first vertex: "))
                    print("The in-degree is ", self._ctrl.get_in_degree(vertex))
                    print("The out-degree is " ,self._ctrl.get_out_degree(vertex))
                
                elif cmd =='4':
                    #4 - iterate in-bound edges of a vertex
                    vertex= int(input("Give the vertex: "))
                    print(" The origin vertices are: ", self._ctrl.iterate_inbound(vertex))
                   
                elif cmd =='5':
                    #5 - iterate out-bound edges of a vertex
                    vertex= int(input("Give the vertex: "))
                    print(" The target vertices are: ", self._ctrl.iterate_outbound(vertex))
                   
                elif cmd =='6':
                    #6 - get the cost of an edge
                    x= int(input("Give the origin vertex: "))
                    y= int(input("Give the target vertex: "))
                    print("The cost is: ", self._ctrl.get_cost(x,y))
                    
                elif cmd =='7':
                    #7 - add a vertex to the graph
                    vertex= int(input("Give the vertex: "))
                    self._ctrl.add_vertex(vertex)
                    print("Successfully added!")
                
                elif cmd =='8':
                    #8 - remove a vertex from the graph
                    vertex=int(input("Give the vertex: "))
                    self._ctrl.remove_vertex(vertex)
                    print("Successfully removed! ")
                
                elif cmd =='9':
                    #9 - add an edge to the graph
                    x= int(input("Give the origin vertex: "))
                    y= int(input("Give the target vertex: "))
                    cost= int(input("Give the cost: "))
                    self._ctrl.add_edge(x,y,cost)
                    print("Successfully added!")
                    
                elif cmd =='10':
                    #10 - remove an edge from the graph
                    x= int(input("Give the origin vertex: "))
                    y= int(input("Give the target vertex: "))
                    self._ctrl.remove_edge(x,y)
                    print("Successfully removed! ")
                    
                elif cmd =='11':
                    #11 - update an edge
                    x= int(input("Give the origin vertex: "))
                    y= int(input("Give the target vertex: "))
                    cost= int(input("Give the cost: "))
                    self._ctrl.update_cost(x,y,cost)
                    print("Successfully updated!")
                    
                elif cmd =='12':
                    #12 - print graph
                    for i in self._ctrl.get_vertices():
                        print(i)
                        print ("In", self._ctrl.iterate_inbound(i))
                        print("Out", self._ctrl.iterate_outbound(i))
                elif cmd=='13':
                    #13 - print graph like in file
                    self.print_graph()
                elif cmd =='14':
                    #14 - print graph using edge_property class
                    self.print_graph_2()
                elif cmd =='0':
                    #exit
                    print ("B-Bye!!!")
                    keepAlive= False
                else :
                    print(" Invalid command. Try again! ")
                    
            except KeyError as msg:
                print(msg)
    
    def print_graph(self):
        """
        Prints the graph like in file, with isolated vertices 
        """
        n=self._ctrl.get_vertices_no()
        m=self._ctrl.get_edges_no()
        print (n," ",m)
        for i in self._ctrl.get_vertices():
            if self._ctrl.get_out_degree(i)!=0:
                for j in self._ctrl.iterate_outbound(i):
                    print(i," ",j," ", self._ctrl.get_cost(i,j))
            else:
                if self._ctrl.get_in_degree(i) == 0:
                    print(i) # isolated vertex
        
    def print_graph_2(self):
        n=self._ctrl.get_vertices_no()
        m=self._ctrl.get_edges_no()
        print (n," ",m)
        for (i,j) in self._ctrl.get_edges().keys():
            print(i," ",j," ", self._ctrl.get_cost(i,j))
    
    




