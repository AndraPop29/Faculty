# 2.  Lottery
# We have  n balls,  p from them are white, and the rest blue. 
# Each ball has a label of character type (letter of the alphabet). 
# Check all the possibilities to select  k balls, at least a of them have 
# to be white, and at least one white ball has to be tagged with a vowel.


from random import shuffle

from math import sqrt

def candidate(k):
	shuffle(balls)
	return balls[0:k]

def quality(l,a):
	n=0
	quality = 0
	ok = 0
	for i in range (0,len(l)):
		if l[i][1] == "white":
			n = n+1
			if l[i][0] in "aeiou":
				ok = 1
	if ok == 0:
		quality = quality +1

	while n < a:
		quality = quality + 1
		n = n+1


	return quality

def generateSample(n):
	sample=[]
	for i in range(0,n):
		sample.append(candidate(3))
	return sample

def calculateMean(l):
	suma = 0
	for i in range(0,len(l)):
		suma = suma+ quality(l[i],3)
	return suma / len(l)

def calculateSD(l,m):
	suma = 0
	for i in range(0,len(l)):
		val = (quality(l[i],3) - m)*(quality(l[i],3) - m)
		suma = suma + val

	return sqrt(suma/len(l))





balls = [['a',"white"],['b',"blue"],['c',"white"],['d',"white"],['e',"blue"]]

# a)

lista=[]
print("Candidate: ")
lista = candidate(3)
print(lista)

# b)

if quality(lista,1) == 0:
	print("It is a viable solution :)")
else:
	print("Not a viable solution :(")

# c)

print("Quality: ")
print(quality(lista,1))

# d)

sample = generateSample(10)
print("Sample: ")
print(sample)
mean = calculateMean(sample)
print("Mean is: ")
print(mean)

sd = calculateSD(sample,mean)
print("Standard deviation is: ")
print(sd)

