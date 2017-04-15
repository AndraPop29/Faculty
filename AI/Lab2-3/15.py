#!/usr/bin/python3

import sys
from copy import deepcopy

class State:
	def __init__(self, values = []):
		self.values = values

	def heuristic(self, finalState):
		return len([x for x, y in zip(self.values, oth.values) if x == y])

	def __eq__(self, oth):
		return len([x for x, y in zip(self.values, oth.values) if x == y]) == len(self.values)

	def __str__(self):
		return str(self.values)

	def __repr__(self):
		return str(self)

class Problem:
	def __init__(self):
		self.initialState = State()
		self.finalState = State()

	def expand(self, state):
		result = []
		result.extend(self.switchLines(state))
		result.extend(self.switchColumns(state))
		return result

	def switchLines(self, state):
		result = []
		for i in range(3):
			c1 = deepcopy(state.values)
			c2 = deepcopy(state.values)
			for j in range(3):
				c1[i * 3 + j] += 1
				c2[i * 3 + j] -= 1
			if self.valid(c1) == True:
				result.append(State(c1))
			if self.valid(c2) == True:
				result.append(State(c2))
		return result

	def switchColumns(self, state):
		result = []
		for i in range(3):
			c1 = deepcopy(state.values)
			c2 = deepcopy(state.values)
			for j in range(3):
				c1[i + j * 3] += 1
				c2[i + j * 3] -= 1
			if self.valid(c1) == True:
				result.append(State(c1))
			if self.valid(c2) == True:
				result.append(State(c2))
		return result

	def valid(self, values):
		for x in values:
			if x > 23 or x < 0:
				return False
		return True

	def heuristic(self, state1, state2):
		if heuristic(state1, self.finalState) > heuristic(state2, self.finalState):
			return -1
		else:
			return 1

	def readFromFile(self, filename):
		with open(filename) as f:
			self.initialState = State([int(x) for x in next(f).split()])
			self.finalState = State([int(x) for x in next(f).split()])

class Controller:
	def __init__(self, problem):
		self.problem = problem

	def dfs(self):
		visited = []
		stack = [self.problem.initialState]
		while len(stack):
			currentState = stack.pop()
			print(currentState)
			if currentState == self.problem.finalState:
				print('Found')
				return
			if currentState not in visited:
				visited.append(currentState)
				stack.extend(self.problem.expand(currentState))
		return visited

	def gbfs(self):
		visited = []
		stack = [self.problem.initialState]
		while len(stack):
			currentState = stack.pop()
			print(currentState)
			if currentState == self.problem.finalState:
				print('Found')
				return
			if currentState not in visited:
				visited.append(currentState)
				children = self.problem.expand(currentState)
				#children.sort(key = lambda x: x.heuristic(self.problem.finalState))
				#print(children)
				stack.extend(children)
		return visited

class UI:
	def __init__(self, controller):
		self.controller = controller

	def mainMenu(self):
		if len(sys.argv) != 2:
			self.printHelp()
			return
		if sys.argv[1] == "dfs":
			self.controller.dfs()
		elif sys.argv[1] == "gbfs":
			self.controller.gbfs()
			

	def printHelp(self):
		print('usage: ./tree_search.py dfs|gbfs')

if __name__ == '__main__':
	problem = Problem()
	problem.readFromFile('clocks.in')
	ui = UI(Controller(problem))
	ui.mainMenu()

