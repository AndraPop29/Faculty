#pragma once

#include "DLL.h"
using namespace std;

template <typename T >
class IteratorDLL : public Iterator <T> {
private:
	Node<T> * current;
	DoublyLinkedList<T> container;

public:
	/*Constructor*/
	IteratorDLL(DoublyLinkedList<T> &container);

	/*Sets the current iterator on the next iterator in the ordered list */
	void next() override;

	/*Sets the current iterator on the previous iterator in the ordered list  */
	void prev() override;

	/*Verifies if the iterator is at the last element.
	Output: boolean value*/
	bool isDone()override;

	/*Initializes the iterator with the first element
	of the ordered list*/
	void beginIt()override;

	/*Adds an element on the current position
	Input: val - type T*/
	void add(T val)override;

	/*Removes the element of the current position
	and the value of the iterator becomes the next one*/
	void remove()override;

	/*Getter of the element from the current position
	Output: Object of type T*/
	T getElem()override;

	/*Setter of the element on the current position
	Input : object of type T*/
	void setElem(T val)override;
};

template<typename T>
inline IteratorDLL<T>::IteratorDLL(DoublyLinkedList<T>& container) : container{ container } {

	this->current = this->container.getHead();
}

template<typename T>
inline void IteratorDLL<T>::next() {
	this->current = this->current->getNext();
}

template<typename T>
inline void IteratorDLL<T>::prev() {
	this->current = this->current->getPrev();
}

template<typename T>
inline bool IteratorDLL<T>::isDone() {
	return this->current == NULL;
}

template<typename T>
inline void IteratorDLL<T>::beginIt() {
	this->current = this->container.getHead();
}

template<typename T>
inline void IteratorDLL<T>::add(T val) {
	Node<T> * NewNode{ val };
	this->container.insertBefore(this->current, *NewNode);
	this->current->getPrev();
}

template<typename T>
inline void IteratorDLL<T>::remove() {
	Node<T> *myNode() = this->current;
	this->current->getNext();
	this->container.deleteNode(myNode);
}

template<typename T>
inline T IteratorDLL<T>::getElem() {
	return this->current->getData();
}

template<typename T>
inline void IteratorDLL<T>::setElem(T val) {
	this->current->setData(val);
}
