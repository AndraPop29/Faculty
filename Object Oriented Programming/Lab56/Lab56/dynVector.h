#pragma once

#include "pet.h"

template<class TElem>

class dynVector {

public:
	dynVector();
	dynVector(const dynVector<TElem> &other);
	dynVector &operator=(const dynVector &other);
	TElem &operator [](int index) const;
	int getLength() { return length };
	~dynVector();
	//void add(const TElem &e);
	void deleteE(int pos);
	int getSize() const;
	TElem* getAllElems() const;
	dynVector &operator+(const TElem &e);



private:
	TElem* elems;
	int size;
	int capacity;
	bool resize();


};

//Constructor for the dynamic vector

template<class TElem>
dynVector<TElem>::dynVector()
{
	this->capacity = 0;
	this->size = 0;
	this->elems = nullptr;
}

//Copy constructor

template<class TElem>
dynVector<TElem>::dynVector(const dynVector<TElem> &other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->elems = new TElem[other.capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = other.elems[i];
	}
}

//Overloading the "=" operator
//The assignment operator is used to copy the values frm one object to another already existing object

template<class TElem>
dynVector<TElem> &dynVector<TElem>::operator=(const dynVector<TElem> &other)
{
	if (this != &other)
	{
		this->size = other.size;
		this->capacity = other.capacity;
		delete[] this->elems;

		this->elems = new TElem[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->elems[i] = other.elems[i];
		}
	}
	return *this;
}

template<class TElem>
dynVector<TElem> &dynVector<TElem>::operator+(const TElem &e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
	return *this;
}

//"-" operator overload!!

template<class TElem>
TElem &dynVector<TElem>::operator[](int index) const
{
	return elems[index];
}

template<class TElem>
bool dynVector<TElem>::resize()
{
	int newCapacity = 2 * capacity + 1;
	TElem *newElems = new TElem[newCapacity];
	if (newElems)
	{
		capacity = newCapacity;
		std::copy(elems,elems+size,newElems);
		delete[] elems;
		elems = newElems;
		return true;

	}
	return false;
}

template<class TElem>
void dynVector<TElem>::deleteE(int pos)
{
	for (int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template<class TElem>
int dynVector<TElem>::getSize() const
{
	return size;
}

template<class TElem>
TElem* dynVector<TElem>::getAllElems() const
{
	return elems;
}

template<class TElem>
dynVector<TElem>::~dynVector()
{
	delete[] elems;
}

