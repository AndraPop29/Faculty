#pragma once
#include"ADTIterator.h"
#include "DVList.h"
#include "DynamicVector.h"
#include<iostream>
using namespace std;

template<typename T>
class IteratorDV : public Iterator<T> {
private:
	int current;
	DynamicVector<T> &container;
public:
	/*Constructor*/
	IteratorDV(DynamicVector<T> &container);

	/*Getter of the next iterator in the ordered list
	Output: next iterator */
	void next();

	void prev();

	/*Verifies if the iterator is at the last element.
	Output: boolean value*/
	bool isDone();

	/*Initializes the iterator with the first element
	of the ordered list*/
	void beginIt();

	/*Adds an element on the current position
	Input: val - type T*/
	void add(T val);

	/*Removes the element of the current position
	and the value of the iterator becomes the next one*/
	void remove();

	/*Getter of the element from the current position
	Output: Object of type T*/
	T getElem();

	/*Setter of the element on the current position
	Input : object of type T*/
	void setElem(T val);

	//~IteratorDV();
};


template<typename T>
IteratorDV<T>::IteratorDV(DynamicVector<T> & container) : container{ container } {
	this->current = 0;
}

template<typename T>
void IteratorDV<T>::next() {
	this->current++;
}

template<typename T>
inline void IteratorDV<T>::prev() {
	this->current--;
}

template<typename T>
inline bool IteratorDV<T>::isDone() {
	return this->current == this->container.getLength();
}

template<typename T>
inline void IteratorDV<T>::beginIt() {
	this->current = 0;
}


template<typename T>
void IteratorDV<T>::add(T val) {
	this->container.add(val, this->current);
}

template<typename T>
void IteratorDV<T>::remove() {
	this->container.remove(this->current);
}

template<typename T>
T IteratorDV<T>::getElem() {
	return this->container[this->current];
}

template<typename T>
void IteratorDV<T>::setElem(T val) {
	this->container[this->current] = val;
}



