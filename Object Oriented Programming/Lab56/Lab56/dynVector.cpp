# include "dynVector.h"
#include<cassert>

dynVector::dynVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

dynVector::dynVector(const dynVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

dynVector::~dynVector()
{
	delete[] this->elems;
}

void dynVector::add(TElement e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;

}

void dynVector::deleteE(int pos)
{
	for (int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}
dynVector& dynVector::operator=(const dynVector& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

void dynVector::resize(double factor)
{
	this->capacity *= factor;

	TElement* e = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = e[i];

	delete[] this->elems;
	elems = e;
}

TElement* dynVector::getAllElems() const
{
	return this->elems;
}

int dynVector::getSize() const
{
	return this->size;
}

void dynVector::testVector()
{
	TElement p{ "Pufoshenie","Poodle",4,"1.jpg" };
	this->add(p);
	assert(this->getSize() == 1);

	this->deleteE(0);
	assert(this->getSize() == 0);

	assert(this->capacity == 10);
	this->resize();
	assert(this->capacity == 20);

}