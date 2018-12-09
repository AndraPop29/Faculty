#pragma once
#include "MatriceRara.h"


class Iterator
{
private:
	friend class MatriceRara;
	MatriceRara* m;
public:
	//Functia constructor default
	Iterator();
	//Functia constructor
	Iterator(MatriceRara*);

	TElement element() {};

	int curent;
	/*
	Functia trece la urmatorul element
	*/
	void urmator();
	/*
	Functia verifica daca itertorul este valid
	*/
	bool valid();

	~Iterator(void);
};