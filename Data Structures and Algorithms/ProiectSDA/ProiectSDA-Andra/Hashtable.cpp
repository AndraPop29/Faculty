#include "Hashtable.h"

#include <iostream>
#include<sstream>
int hashCode(TKey c) {
	int n, nr;
	n = 0;
	nr = 0;
	for (int i = 1; i < c.size(); i += 2)
	{
		istringstream(c[i]) >> n;
		nr = nr + n;
	}
	return nr;
}

Node::Node(TKey c, TValue v, PNode urm) {
	this->c = c;
	this->v = v;
	this->urm = urm;
}

int Hashtable::d(TKey c) {
	//hashing through division
	return hashCode(c);
}


Hashtable::Hashtable() {
	m = MAX; 
	for (int i = 0; i<m; i++)
		l[i] = NULL;
}


void Hashtable::add(TKey c, TValue v) {
	//hash location for the key
	int i = d(c);
	//create a Node
	PNode p = new Node(c, v, NULL);
	//add to the front of the list
	p->urm = l[i];
	l[i] = p;
}
TElem Hashtable::remove(TKey c) {
	int position = d(c);
	PNode current = l[position];
	TElem deleted;
	deleted.c = -1;
	deleted.v = -1;

	if (current == NULL) { // empty chain
		return deleted;
	}
	else if (current->c == c) { //if I have to delete the first element of the chain
		l[position] = current->urm;
		deleted.c = current->c;
		deleted.v = current->v;
		delete current;
	}
	else {
		while (current->urm != NULL && current->urm->c != c) { //find the node BEFORE the node with key c
			current = current->urm;
		}
		if (current->urm != NULL) {
			deleted.c = current->urm->c;
			deleted.v = current->urm->v;
			PNode toDelete = current->urm;
			current->urm = current->urm->urm;
			delete toDelete;
		}
	}
	return deleted;
}
TValue Hashtable::search(TKey c) {
	int position = d(c);
	TValue result = "";
	PNode current = l[position];
	while (current != NULL && current->c != c) {
		current = current->urm;
	}
	if (current != NULL) {
		result = current->v;
	}
	return result;
}
int Hashtable::isValid(TKey key1, TKey key2)
{
	int i, j;
	string s1 = "";
	string s2 = "";
	int ok = 0;
	for (i = 0; i < key1.size(); i += 2)
	{
		s1 = key1[i] + key1[i + 1];
		for (j = 0; j < key2.size(); j += 2)
		{
			s2 = key2[j] + key2[j + 1];

			if (s1 == s2)
			{
				ok = 1;
				break;
			}
		}
		if (!ok)
			return 0;
		s1 = "";
		s2 = "";
		ok = 0;
	}
	return 1;
}
void Hashtable::anagrams(TKey c)
{
	int position = d(c);
	PNode current = l[position];
	while (current != NULL)
	{
		if (isValid(current->c, c))
			cout << current->v << endl;
		current = current->urm;
	}
}
Iterator Hashtable::iterator() const {
	return Iterator(*this);
}

Hashtable::~Hashtable() {
	//empty the memory for the lists
	for (int i = 0; i<m; i++) {
		//empty the memory for the list i
		while (l[i] != NULL) {
			PNode p = l[i];
			l[i] = l[i]->urm;
			delete p;
		}
	}
}

void Iterator::iterate() {
	//find the first non-empty list starting from poz
	while (poz<dct.m && dct.l[poz] == NULL) poz++;
	if (poz<dct.m)
		curent = dct.l[poz];
}

//constructor iterator
Iterator::Iterator(const Hashtable& d) :
	dct(d) {
	poz = 0;
	iterate();
}

void Iterator::first() {
	//deteremine the first non-empty list
	poz = 0;
	iterate();
}

void Iterator::next() {
	curent = curent->urm;
	if (curent == NULL) {
		poz = poz + 1;
		iterate();
	}
}

bool Iterator::valid() const {
	return (poz<dct.m) && (curent != NULL);
}

TElem Iterator::element() const {
	TElem e;
	e.c = curent->c;
	e.v = curent->v;
	return e;
}



