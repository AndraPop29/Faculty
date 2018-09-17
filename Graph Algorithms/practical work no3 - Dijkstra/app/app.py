'''
Created on 7 mar. 2016

@author: Pop Andra
'''
from ui.UI import Ui
from Controller.GraphController import Graph_Controller
from domain.DirectedGraphs import*
from domain.EdgeProperty import *

aController = Graph_Controller("graph.txt")
aUi= Ui(aController)
aUi.main_menu()
