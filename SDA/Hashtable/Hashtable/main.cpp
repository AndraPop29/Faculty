#include<iostream>

using namespace std;

#define MAX 26
class Node {
private:
	int val;
	Node* next;
public:
	friend class Hashtable;
	friend class Iterator;
	Node(int val, Node* next)
	{
		this->val = val;
		this->next = next;
	}
};
int hashCode(int c)
{
	return (c%MAX);
}

class Hashtable 
{
private:
	int m;//number of locations
	Node* l[26];
	inline int d(int c)
	{
		return hashCode(c);
	}
public:
	friend class Iterator;
	Hashtable()
	{
		m = MAX;
		for (int i = 0; i < m; i++)
			l[i] = NULL;
	}
	Iterator iterator() const;
	/*inline Iterator iterator() const {
		return Iterator(*this);
	}*/
	inline void add(int c)
	{
		//hash location for the key
		int i = d(c);
		Node* p = new Node(c, NULL);
		//add to the front of the list
		p->next = l[i];
		l[i] = p;

	}
	inline int remove(int c)
	{
		int position = d(c);
		Node* current = l[position];
		int deleted;
		deleted = -1;
		if (current == NULL)//empty chain
			return deleted;
		else if (current->val == c) {//if I have to delete the first element of the chain
			l[position] = current->next;
			deleted = current->val;
			delete current;
		}
		else {
			while (current->next != NULL && current->next->val != c)
				current = current->next;
		}
		if (current->next != NULL)
		{
			deleted = current->next->val;
			Node* toDelete = current->next;
			current->next = current->next->next;
			delete toDelete;
		}
		return deleted;
	}
	inline bool search(int c)
	{
		int pos = d(c);
		Node* current = l[pos];
		while (current != NULL && current->val != c)
			current = current->next;
		if (current != NULL)
			return true;
		return false;

	}
	~Hashtable() {
		//empty the memory for the lists
		for (int i = 0; i<m; i++) {
			//empty the memory for the list i
			while (l[i] != NULL) {
				Node* p = l[i];
				l[i] = l[i]->next;
				delete p;
			}
		}
	}

};
class Iterator {
private:

	const Hashtable& h;
	//the current location in the table
	int poz;
	//holds the current position inside the list at the current location-
	//the adress of the current node in the associated list
	Node* curent;
public:
	friend class Hashtable;
	//in order to construct an iterator for a map it is necessary
	//for a pointer or reference to it to be given to the constructor

	Iterator(const Hashtable& hash);// : h(hash)
	//{
	//	poz = 0;
	//	iterate();
	//}
	inline void iterate() {
		while (poz < h.m && h.l[poz] == NULL)
			poz++;
		if (poz < h.m)
			curent = h.l[poz];
	}
	inline void first() {
		poz = 0;
		iterate();
	}

	inline void next() {
		curent = curent->next;
		if (curent == NULL) {
			poz = poz + 1;
			iterate();
		}
	}
	inline bool valid() const {
		return (poz < h.m) && (curent != NULL);
	}
	inline int element()const {
		int e = curent->val;
		return e;
	}
	~Iterator() {}


};

Iterator::Iterator(const Hashtable& hash) : h(hash)
{
	poz = 0;
	iterate();
}
Iterator Hashtable::iterator() const {
	return Iterator(*this);
}
int main()
{

	Hashtable h;

	h.add(15);
	h.add(35);
	h.add(7);
	h.add(13);
	h.add(2);
	h.add(27);
	//Iterator it(h);
	Iterator it=h.iterator();
	//Iterator* it = new Iterator(h);

	while (it.valid())
	{
		cout << it.element()<<endl;
		it.next();
	}
	int d=h.remove(13);
	while (it.valid())
	{
		cout << it.element() << endl;
		it.next();
	}

	system("pause");
	return 0;
}