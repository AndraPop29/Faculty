#pragma once

#include "dynVector.h"
#include<iostream>
class catalog
{
private:
	dynVector<pet> pets;
	dynVector<pet> adoptList;
	int current;

public:
	catalog();

	void add(const pet& p);

	pet catalog::getCurrentDog();
	dynVector<pet> catalog::getDogs()
	{
		return pets;
	}
	dynVector<pet> catalog::getList()
	{
		return adoptList;
	}
	
	void view();
	//shows the current dog
	void next();
	//shows the next dog
	bool isEmpty();
	//returns true if the list is empty
	//false otherwise
	void clear();
	//Deletes all of the elements from the catalog
	void addToList(const pet& p);
	//Adds a pet to the adoption list
	//Input:p-pet
	//Output:-
	void testCat();
};
