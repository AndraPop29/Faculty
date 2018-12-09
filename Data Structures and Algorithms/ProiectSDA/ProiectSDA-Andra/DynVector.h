#pragma once
#include "abstractmap.h"
#include <iostream>


template<class Object>

class DynamicVector: public AbstractMap <Object>{

public:
	// implicit constructor for DynamicVector 
	DynamicVector();
	DynamicVector(const DynamicVector<Object> &other);
	// assignment operator overloading
	DynamicVector &operator=(const DynamicVector &other);
	//	Overloading the subscript operator
	//	Input - position
	//	Precondition - position is int type
	//	Output - a reference to the element of input position
	Object &operator [](int index) const;
	//	Adds an element to the current DynamicVector
	//	Input - element
	//	Preconditions - element is type Object
	//	Output - None
	void put(const Object& e) override;
	//	Removes element from input position from DynamicVector
	//	Input - position
	//	Preconditions - position is int type
	//	Output - None
	void remove(int index) override;
	//	Returns the size of DynamicVector
	//	Input - None
	//	Output - size
	//	Postconditions - size is int type
	int getSize() const override;
	//	Returns the capacity of DynamicVector
	//	Input  - None
	//	Output - capacity
	//  Postconditions - capacity is int type
	int get_capacity(void);
	
	bool isEmpty();
	//descructor for dynamic vector
	Object* getAllElems() const;
	~DynamicVector();
	



private:
	Object* elems;
	int size;
	int capacity;
	bool resize();


};

//Constructor for the dynamic vector

template<class TE>
DynamicVector<TE>::DynamicVector()
{
	this->capacity = 0;
	this->size = 0;
	this->elems = nullptr;
}

//Copy constructor

template<class TE>
DynamicVector<TE>::DynamicVector(const DynamicVector<TE> &other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->elems = new TE[other.capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = other.elems[i];
	}
}

//Overloading the "=" operator
//The assignment operator is used to copy the values frm one object to another already existing object

template<class TE>
DynamicVector<TE> &DynamicVector<TE>::operator=(const DynamicVector<TE> &other)
{
	if (this != &other)
	{
		this->size = other.size;
		this->capacity = other.capacity;
		delete[] this->elems;

		this->elems = new TE[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->elems[i] = other.elems[i];
		}
	}
	return *this;
}


template<class TE>
TE &DynamicVector<TE>::operator[](int index) const
{
	return elems[index];
}


template<class TE>
void	DynamicVector<TE>::put(const TE& e) 
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size += 1;

}


template<class TE>
bool DynamicVector<TE>::resize()
{
	int newCapacity = 2 * capacity + 1;
	TE *newElems = new TE[newCapacity];
	if (newElems)
	{
		capacity = newCapacity;
		std::copy(elems, elems + size, newElems);
		delete[] elems;
		elems = newElems;
		return true;

	}
	return false;
}

template <class TE>
void	DynamicVector<TE>::remove(int position) 
{
	if (position >= this->size)
		return;
	if (this->size == 1)
	{
		this->size--;
		return;
	}

	for (int i = position; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}
template<class TE>
int DynamicVector<TE>::getSize() const
{
	return size;
}

template<class TE>
TE* DynamicVector<TE>::getAllElems() const
{
	return elems;
}



template <class TE>
int	DynamicVector<TE>::get_capacity(void)
{
	return (this->capacity);
}

template<class TE>
bool DynamicVector<TE>::isEmpty()
{
	if (this->size == 0)
		return true;
	return false;
}
template<class TE>
DynamicVector<TE>::~DynamicVector()
{
	delete[] elems;
}


