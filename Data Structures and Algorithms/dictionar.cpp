#include "dictionar.h"
#include <iostream>

int hashCode(TKey c){
   return c;
}

SLNode::SLNode(TKey c, TValue v, PSLNode next) {
	this->c = c;
	this->v = v;
	this->next = next;
}

int Dictionary::d(TKey c) const{
	return hashCode(c)%m;
}


Dictionary::Dictionary() {
    m=MAX; 
	for (int i=0;i<m;i++)
        t[i] = NULL;
}

void Dictionary::add(TKey c, TValue v) {
	int i=d(c);
	PSLNode p = new SLNode(c, v, NULL);
	p->next = t[i];
    t[i]=p;
}

TPair Dictionary::remove(TKey c) {
	int position = d(c);
	PSLNode current = t[position];
	TPair deleted;
	deleted.c = -1;
	deleted.v = -1;

	if (current == NULL) { // empty chain
		return deleted;
	}
	else if (current->c == c) { //if I have to delete the first element of the chain
		t[position] = current->next;
		deleted.c = current->c;
		deleted.v = current->v;
		delete current;
	}
	else {
		while (current->next != NULL && current->next->c != c) { //find the node BEFORE the node with key c
			current = current->next;
		}
		if (current->next != NULL) {
			deleted.c = current->next->c;
			deleted.v = current->next->v;
			PSLNode toDelete = current->next;
			current->next = current->next->next;		
			delete toDelete;
		}
	}
	return deleted;
}

TValue Dictionary::search(TKey c) const {
	int position = d(c);
	TValue result = -1;
	PSLNode current = t[position];
	while (current != NULL && current->c != c) {
		current = current->next;
	}
	if (current != NULL) {
		result = current->v;
	}
	return result;
}



Iterator Dictionary::iterator() const{
	return Iterator(*this);
}

Dictionary::~Dictionary() {
	//we have to delete the chains
	for (int i=0;i<m;i++){
    //delete chain from position i
      while (t[i] != NULL) {
		PSLNode p = t[i];
		t[i] = t[i]->next;
		delete p;
	  }
    }
}

void Iterator::findFirstEmpty(){
      while (currentPos < dct.m && dct.t[currentPos]==NULL) currentPos++;
      if (currentPos<dct.m)
	    currentNode=dct.t[currentPos];
}

Iterator::Iterator(const Dictionary& d) :
		dct(d) {
	currentPos=0;
    findFirstEmpty();
}

void Iterator::next() {
   currentNode=currentNode->next;
   if (currentNode==NULL){
      currentPos=currentPos+1;
      findFirstEmpty();
   }
}

bool Iterator::hasNext() const {
	return (currentPos<dct.m) && (currentNode != NULL);
}

TPair Iterator::element() const {
	TPair e;
	e.c=currentNode->c;
	e.v=currentNode->v;
	return e;
}
