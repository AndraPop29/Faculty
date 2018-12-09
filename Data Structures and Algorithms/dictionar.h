#ifndef DICTIONAR_H
#define DICTIONAR_H

#define MAX 10 //initial table size

typedef int TKey;
typedef int TValue;

typedef struct TPair{
    TKey c;
    TValue v;
   }TPair;

//function that returns the hashCode of a key

int hashCode(TKey c);

//Iterator class forward declaration
class Iterator;

//forward declaration of SLNode class ...
class SLNode;

//so that we can define a pointer to s SLNode class
typedef SLNode *PSLNode;

class SLNode
	{
	private:
		TKey c;
		TValue v;
		PSLNode next;
	public:
	    friend class Dictionary;
	    friend class Iterator;
        //constructor
		SLNode(TKey e, TValue v, PSLNode next);
};

//Dictionary on hash tbale with chaining 
class Dictionary {
private:
    int m; //number of positions
	PSLNode t[MAX]; //static vector for the linked lists

	//hash function - by division
	int d(TKey c) const;

public:
	friend class Iterator;
	Dictionary();

	void add(TKey c, TValue v);

	Iterator iterator() const;

	TPair remove(TKey c);

	TValue search(TKey c) const;

	~Dictionary();

};


class Iterator {
private:
	Iterator(const Dictionary& d);
    void findFirstEmpty();


	const Dictionary& dct;
    int currentPos;
	PSLNode currentNode;
public:

    friend class Dictionary;

	void next();
	bool hasNext() const;
	TPair element() const;
};

#endif
