#pragma once
#include "Lista.h"
#include "TElement.h"
#include "Iterator.h"

class Iterator;
class MatriceRara
{
public:
	MatriceRara();
	friend class Iterator;
	Lista lista;
	/*
	Functia returneaza elementul anterior celui dat
	*/
	TElement cauta(TElement);
	/*
	Functia adauga elemente in matrice
	*/
	void adaugaMatrice(TElement);
	/*
	Functia pentru afisare a matricei
	*/
	void afisareMatrice();
	/*
	Functia returneaza valoarea de pe o linie si de pe o coloana
	*/
	int getValoare(int, int);
	/*
	Functia sterge un element din matrice
	*/
	void stergeMatrice(TElement);
	/*
	Functia de creare a unui iterator
	*/
	Iterator* Itr();
	/*
	Functia destructor
	*/
	~MatriceRara(void);
	/*
	Functia returneaza 1 daca exista element in matrice si 0 in caz contrar
	*/
	int cautareSeparata(TElement e);
	/*
	Functia returneaza nr de linii a matricei
	*/
	int getNrLinii();
	/*
	Functia returneaza numarul de coloane a matricei
	*/
	int getNrColoane();

};

