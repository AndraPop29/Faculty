
class Stack:
     def __init__(self):
         self.items = []

     def isEmpty(self):
         return self.items == []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()

     def peek(self):
         return self.items[len(self.items)-1]

     def size(self):
         return len(self.items)

class Problem:
	def __init__(self):
		self.elements = []
		self.readFromFile()
		self.initState = self.elements
		self.finalState = []

	def readFromFile(self):
		file = open('lab2.txt', 'r')
		for line in file:
			line = (int)(line.strip())
			self.elements.append(line)

	def interchange(self,state1,i,j):
		aux = state1[i]
		state1[i] = state1[j]
		state1[j] = aux

	def expand(self,state):
		listNew = []
		s = 0
		if self.heuristic(state) == 0:
			return []
		else:
			for i in range(0,len(state)-1):
				for j in range(i+1,len(state)):
					if state[i] > state[j]:
						newState = state[:]
						self.interchange(newState,i,j)
			
						listNew.append(newState)
		return listNew	

	def heuristic(self,state):
		h = 0
		for i in range(0,len(state)-1):
			for j in range(i+1, len(state)):
				if state[i] > state[j]:
					h = h + 1
		return h



class Controller:
	def __init__(self):
		self.problem = Problem()
		self.stack = Stack()

	def addToStack(self,children):
		for i in children:
			self.stack.push(i)	

	def emptystack(self):
		while not self.stack.isEmpty():
			self.stack.pop()

	def DFS(self):
		self.stack.push(self.problem.initState)
		ok = False
		while self.stack.size() > 0 and not ok:
			State = self.stack.pop()
			'''print State'''
			children = self.problem.expand(State)
			
			self.addToStack(children)
			if len(children) == 0:
				ok = True

		self.problem.finalState = State
		self.emptystack()

	def interchange(self,state,i,j):
		aux = state[i]
		state[i] = state[j]
		state[j] = aux

	def orderGBFS(self,childs):
		for i in range (0,len(childs)-1):
			for j in range (i+1,len(childs)):
		
				if self.problem.heuristic(childs[i]) > self.problem.heuristic(childs[j]):

					self.interchange(childs,i,j)
				
		i = len(childs) - 1 
	
		while i > -1:
			self.stack.push(childs[i])
			i = i - 1



	def GBFS(self):
		self.stack.push(self.problem.initState)
		ok = False
			
		while not self.stack.isEmpty() and not ok:
			State = self.stack.pop()
			children = self.problem.expand(State)
			'''print State'''
			if len(children) == 0:
				ok = True
			else:
				self.orderGBFS(children)
				
		

		self.problem.finalState = State
		self.emptystack()



class UI:
	def __init__(self):
		self.Controller = Controller()

		print "Solve sorting problem using DFS:"
		self.Controller.DFS()
		print "The final state is:"
		print self.Controller.problem.finalState

		print "Solve sorting problem using GBFS:"
		self.Controller.GBFS()
		print "The final state is:"
		print self.Controller.problem.finalState


if __name__ == '__main__':
	ui = UI()






