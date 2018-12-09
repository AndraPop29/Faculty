#pragma once
#include<string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MAX 26 //maximum table locations

typedef string TKey;
typedef string TValue;

typedef struct TElem {
	TKey c;
	TValue v;
}TElem;

//function which gives the <hashCode> for a key

int hashCode(TKey c);

//reference to class Iterator for using the iterator instances
class Iterator;

//reference to the class Node
class Node;

//define the type PNode as the address of a node
typedef Node *PNode;

class Node
{
private:
	TKey c;
	TValue v;
	PNode urm;
public:
	friend class Hashtable;
	friend class Iterator;
	//constructor
	Node(TKey e, TValue v, PNode urm);
};

//class which defines the representation and functions of the Map ADT

//representation using a data structure - collision resolution through chaining(independent lists)
class Hashtable {
private:
	int m; //the number of locations in the hashtable
	PNode l[MAX]; //independent lists-static vector

				 //hash function
	int d(TKey c);

public:
	//clasa Iterator has to be a friend of Hashtable map
	//in order to have access to its private elements
	friend class Iterator;
	//the implicit constructor
	Hashtable();
	//add a pair (cheie, valoare) to Map
	void add(TKey c, TValue v);
	//returns an iterator for the Map
	Iterator iterator() const;
	TElem remove(TKey c);
	TValue search(TKey c);
	int isValid(TKey c1, TKey C2);
	//function which searches for anagrams
	void anagrams(TKey c);
	// destructor of the Map
	~Hashtable();

};

//iterator for the Map
class Iterator {
private:
	//in order to construct an iterator for a map it is necessary for a pointer or reference to it to be given to the constructor
	Iterator(const Hashtable& d);
	void iterate();
	//contains a reference to the map that is being iterated
	const Hashtable& dct;
	//the current location in the table
	int poz;
	//holds the current position inside the list at the current location - the adress of the current node in the associated list
	PNode curent;
public:

	friend class Hashtable;

	//resets the position of the iterator at the beginning of the map
	void first();
	//moves the iterator to the next position in the map
	void next();
	//verifies if the iterator is valid(indicates an element of the map)
	bool valid() const;
	//returns the current value of the element in the map
	TElem element() const;
};

#endif

