from random import*
import itertools

class Problem:
	def __init__(self, fname):
		self.n = 0
		self.size = 2 * self.n
		self.words = []
		self.load(fname)


	def load(self, fname):
		file = open(fname, 'r')
		self.n = [int(x) for x in next(file).split()]
		for line in file:
			for x in line.split():
				print(x)
				self.words.append(x)

class Individ:
	def __init__(self, perm, pr):
		self.size = len(perm)
		#self.perm = self.all_perms(pr.list)
		self.i = 0
		self.pr = pr
		self.x = perm
		self.f = 0

	def fitness(self):
		#list2 = self.x[:-self.size//2]
		list2 = self.x[3:]
		cuv = ""
		for k in range (0,(self.size)//2): #parcurg literele
			for j in range (0,self.size//2): #parcurg cuvintele
				cuv = cuv + self.pr.list[self.x[j]][k]
			if cuv not in list2:
				self.f = self.f + 1
				cuv = ""

	def swap(self, list, i1, i2):
		list[i1], list[i2] = list[i2], list[i1]

	def permutare(self, lista, start):
		if start >= len(lista):
			return [list(lista)]
            	
		output = []
		for idx in range(start, len(lista)):
			return self.swap(lista, start, idx)
			output.extend(self.permutare(lista, start + 1))
			self.swap(lista, start, idx) 
		return output

	

class Population:
	def __init__(self, nI, pr):
		self.nI = nI
		self.perm = self.all_perms(6)
		self.pr = pr
		#self.v = [Individ(self.perm[0]) for k in range(0,self.nI)]

		
		self.v = [Individ(self.perm[randint(0,len(self.perm)-1 )], self.pr) for k in range(0,self.nI)]


	def all_perms(self,n):
		lista = list(xrange(n))
		return list(itertools.permutations(lista))

	def perm(self, lista):
		return self.all_perms(lista)

	def eval(self, pr):
		for val in self.v:
			#print(val.x)
			val.f

	def reunion(self, toAdd):
		self.v = self.v + toAdd.v
		self.nI = self.nI + toAdd.nI


	def selection(self, n):
		if n < self.nI:
			self.v = sorted(self.v, key =  lambda Individ : Individ.f)
		self.v = self.v[:n]
		self.noI = n;

	def best(self, n):
		aux = sorted(self.v, key =  lambda Individ : Individ.f)
	
		return aux[:n]

class Algorithm:
	def __init__(self, nI, nG, fInput):
		self.noI = nI
		self.noG = nG
		self.pr = Problem(fInput)
		self.p = Population(self.noI, self.pr)
		self.p.eval(self.pr)

	def iteration(self):
		shuffle(self.p.v)
		no = self.noI // 2
		offspring = Population(100, self.pr)
		
		for k in range(0, no):
			#offspring.v.append(self.crossover(self.p.v[2 * k], self.p.v[2 * k + 1]))
			self.mutate(offspring.v)
			#print(offspring.v)

			
		offspring.noI = no
		offspring.eval(self.pr)
		self.p.reunion(offspring)
		self.p.selection(self.noI)

	def run(self):
		for k in xrange(self.noG):
			self.iteration()
		return self.p.best(2)

	def crossover(self, i1, i2):
		
		child = Individ([],self.pr)
		for k in xrange(0, len(i1.x)):
			if random() < 0.5:
				child.x.append(i1.x[k])
			else:
				child.x.append(i2.x[k])
	
		return child

	def swap2(self, lista, i1, i2):
		lista[i1], lista[i2] = lista[i2], lista[i1]

		
	
	def mutate(self, ind):
		i = randint(0, len(ind))
		
		ind[1], ind[2] = ind[2], ind[1]

			

			


if __name__ == '__main__':
	
	alg = Algorithm(100, 100, "Lab3.txt")
	result = alg.run()
	'''
	for i in range (0, len(result)):
		print(result[i].x)
		'''
	#print(result[0].x)
	
	'''
	pr = Problem()
	ind = Individ(pr)
	print ind.all_perms(["AGE","AGO","BEG","CAB","CAD","DOG"])
	'''

