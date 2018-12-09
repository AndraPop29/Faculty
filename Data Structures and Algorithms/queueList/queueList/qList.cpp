#include "qList.h"
#include<string>
#include<iostream>

using namespace std;


Nod::Nod(TElem e, PNod next) {
	this->e = e;
	this->next = next;
}

TElem Nod::element() {
	return e;
}

PNod Nod::nextN() {
	return next;
}

qList::qList()
{
	first = NULL;
}
PNod qList::search(TElem el)
{
	PNod p = first;
	while (p != NULL)
	{
		if (p->e == el)
			return p;
		p = p->next;
	}
	return NULL;

}
void qList::remove(PNod p)
{
	PNod prev = first;
	while (prev->next != NULL && prev->next != p)
		prev = prev->next;

	// Check if node really exists in Linked List
	if (prev->next == NULL)
	{
		printf("\n Given node is not present in Linked List");
		return;
	}

	// Remove node from Linked List
	prev->next = prev->next->next;

	// Free memory
	//free(n);
}
void qList::enqueue(TElem a)
{
	if (search(a) != NULL)
		remove(search(a));
	PNod q = new Nod(a, NULL);
	if (first == NULL)
		first = q;
	else {
		PNod p = first;
		// se parcurge lista pana la ultimul nod
		for (; p->next != NULL; p = p->next);
		//se adauga q dupa p
		p->next = q;
		//cout << p->e;

	}
	t.insert(q);
}
bool qList::isEmpty()
{
	if (first == NULL)
		return true;
	return false;
}

void qList::dequeue()
{
	if(first==NULL)
	{
		printf("There is only one node. The list can't be made empty ");
		return;
	}

	/* Copy the data of next node to head */
	first->e= first->next->e;

	// store address of next node
	PNod n =first->next;

	// Remove the link of next node
	first->next = first->next->next;

	// free memory
	//free(n);
}
void qList::print()
{
	PNod p = first;
	while (p != NULL)
	{
		cout << p->e;
		p = p->next;
	}
}

qList::~qList()
{
}
