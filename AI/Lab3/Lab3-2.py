from random import*
import itertools
import math

class Problem:
	def __init__(self, fname):
		self.n = 0
		self.size = 0
		self.words = []
		self.load(fname)


	def load(self, fname):
		file = open(fname, 'r')
		for x in  next(file).split():
			self.n = int(x)
		self.size = 2 * self.n
		for line in file:
			for x in line.split():
				self.words.append(x)

class Individ:
	def __init__(self, pr):
		self.size = pr.size
		self.x = list(xrange(self.size))
		shuffle(self.x)
		self.f = 0

	def fitness(self, pr):
		list2 = []
		for x in self.x[self.size//2:]:
			list2.append(pr.words[x])
		
		cuv = ""
		for k in range (0,self.size//2): #parcurg literele
			for j in range (0,self.size//2): #parcurg cuvintele
				cuv = cuv + pr.words[self.x[j]][k]
			if cuv not in list2:
				self.f = self.f + 1
			cuv = ""

	def getWords(self, ind, pr):
		lista = []
		for i in ind:
			lista.append(pr.words[i])
		return lista

	def mutate(self, prob):
		k = randint(0,10)
		if k == 1:
			k = randint(0,self.size - 1)
			a = self.x[k]
			self.x[k] = self.x[k - 1]
			self.x[k - 1] = a

	def crossover(self, i2, pr, prob):
		child = Individ(pr)
		subs = self.size // 2 #size of subset

		p = randint(0,10)
		if p <= prob:
			subset = []
			k = randint(0,self.size - 1)

			for i in xrange(subs):
				if k < self.size - 1:
					k = k + 1
				else:
					k = 0
				child.x[k] = self.x[k]
				subset.append(self.x[k])

			if k < self.size - 1:
				j = k + 1
			else:
				j = 0
			ok = 0
			while ok < subs:
				if k < self.size - 1:
					k = k + 1
				
				else:
					k = 0
				if i2.x[k] not in subset:
					ok = ok + 1
					child.x[j] = i2.x[k]
					if j < self.size - 1:
						j = j + 1
					else:
						j = 0
			

			return child
		return self



class Population:
	def __init__(self, nI, pr):
		self.nI = nI
		self.pr = pr 
		self.v = [Individ(pr) for k in xrange(self.nI)]

	def eval(self, pr):
		for val in self.v:
			val.fitness(pr)

	def reunion(self, toAdd):
		self.v = self.v + toAdd.v
		self.nI = self.nI + toAdd.nI


	def selection(self, n):
		#if n < self.nI:
		self.v = sorted(self.v, key =  lambda Individ : Individ.f)
		self.v = self.v[:n]
		self.noI = n;

	def best(self, n):
		aux = sorted(self.v, key =  lambda Individ : Individ.f)
		return aux[:n]

class Algorithm:
	def __init__(self, fInput, fparam):
		self.noI = 0
		self.noG = 0
		self.crossProb = 0
		self.mutProb = 0
		self.readParam(fparam)
		self.pr = Problem(fInput)
		self.p = Population(self.noI, self.pr)
		self.p.eval(self.pr)
		
	def iteration(self):
		shuffle(self.p.v)
		no = self.noI // 2
		offspring = Population(0, self.pr)

		for k in range(0, no):
			offspring.v.append(self.p.v[2*k].crossover(self.p.v[2 * k + 1], self.pr, self.crossProb))
			#self.mutate(offspring.v[k])
			offspring.v[k].mutate(self.mutProb)

		offspring.noI = no
		offspring.eval(self.pr)
		self.p.reunion(offspring)
		
		self.p.selection(self.noI) 
	
	def run(self):
		for k in xrange(self.noG):
			self.iteration()
		return self.p.best(10)

	def readParam(self, fname):
		file = open(fname, 'r')
		content = file.read().split()

		self.mutProb = (int)(content[0])
		self.crossProb = (int)(content[1])
		self.noI = (int)(content[2])
		self.noG = (int)(content[3])


	def average(self, best):
		s = 0
		for x in best:
			print(x.x)
			print(x.f)
			s = s + x.f
		return s/len(best)

	def stand_deviation(self, best, av):
		suma = 0
		for x in best:
			suma = suma + (x.f - av)*(x.f - av)

		return math.sqrt(suma/len(best))






	'''

	def mutate(self, ind):

		k = randint(0,ind.size - 1)
		a = ind.x[k]
		ind.x[k] = ind.x[k - 1]
		ind.x[k - 1] = a


	def crossover(self, i1, i2):
		child = Individ(self.pr)
		subs = i1.size // 2 #size of subset

		subset = []
		k = randint(0,i1.size - 1)
		for i in xrange(subs):
			if k < i1.size - 1:
				k = k + 1
			else:
				k = 0
			child.x[k] = i1.x[k]
			subset.append(i1.x[k])

		if k < i1.size - 1:
			j = k + 1
		else:
			j = 0
		ok = 0
		while ok < subs:
			if k < i1.size - 1:
				k = k + 1
				
			else:
				k = 0
			if i2.x[k] not in subset:
				ok = ok + 1
				child.x[j] = i2.x[k]
				if j < i1.size - 1:
					j = j + 1
				else:
					j = 0
			

		return child

	'''


if __name__ == '__main__':
	alg = Algorithm('Lab3.txt','param.in')
	result = alg.run()
	pr = Problem('Lab3.txt')
	ind = Individ(pr)

	#for i in range(0,len(result)):
	for j in range(0,len(ind.getWords(result[0].x,pr))//2):
		print(ind.getWords(result[0].x,pr))[j]

	print(result[0].f)
	av = alg.average(result)
	print(av)
	print(alg.stand_deviation(result, av))

