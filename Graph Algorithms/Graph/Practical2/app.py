'''
Created on Mar 11, 2016

@author: Andra
'''
from Graph import *
from Repo import *
from UI import *

from edgeProperty import *
from Controller import *



#file=input("Give file name: ")
arepo=repo("grafe.txt")
acon=controller(arepo)
aui=UI(acon)
aui.mainMenu()

