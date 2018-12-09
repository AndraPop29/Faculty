#include "catalog.h"
#include<iostream>
#include<cassert>
using namespace std;
catalog::catalog()
{
	this->current = 0;
}

void catalog::add(const pet& p)
{
	//this->pets.add(p);
	this->pets + p;
}

pet catalog::getCurrentDog()
{
	if (this->current == this->pets.getSize())
		this->current = 0;
	pet* elems = this->pets.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return pet{};
}

void catalog::view()
{
	
	this->current = 0;
	pet currentPet = this->getCurrentDog();
	currentPet.view();

}

void catalog::next()
{
	if (this->pets.getSize() == 0)
		return;
	this->current++;
	pet currentDog = this->getCurrentDog();
	currentDog.view();

}
bool catalog::isEmpty()
{
	return this->pets.getSize() == 0;
}
void catalog::clear()
{
	dynVector<pet> v = this->pets;
	pet* p = this->pets.getAllElems();
	int i = 0;
	while (this->pets.getSize())
	{
		this->pets.deleteE(i);
		i++;
	}


}

void catalog::addToList(const pet& p)
{
	this->adoptList + p;
}

void catalog::testCat()
{
	pet p{ "Pufoshenie","Poodle",4,"1.jpg" };
	//test adding

	this->add(p);
	assert(this->pets.getSize() == 1);

	this->clear();
	assert(this->isEmpty() != 0);


}