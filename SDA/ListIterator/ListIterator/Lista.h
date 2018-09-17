#pragma once
#include "TElement.h"
#define dim 66

struct TNod {
	TElement data;
	int urmator;
	int precedent;
};

class Lista
{
public:
	struct TNod ListaD[dim];
	int ultim;
	int primLiber;
	int prim;
	int dimensiune;

	Lista();

	//void afisare();
	/*	functia cauta primLiber in lista
	pre: -
	post: primLiber
	*/
	void cautaPrimLiber();
	/* functia adauga un element la FINALUL listei sau daca lista e vida, adauga un element pe prima pozitie din lista
	preconditii: elem - TElement
	ListaD[] - TNod
	ultim - pozitia ultimului element din lista
	postconditii: ListaD[] cu un nou element de tip TElement
	*/
	void adauga(TElement elem);
	/*	functia adauga un element(elNou) dupa un alt element din lista
	preconditii: element - TElement
	elNou - TElement
	postconditii: ListaD[] - TNod, cu elementul elNou adaugat dupa element
	*/
	void adaugaDupa(TElement, TElement);
	/*	functia sterge un element de tip TElement din lista
	preconditii: element - TElement
	postconditii: ListaD = ListaD - element
	*/
	void sterge(TElement);
	/*
	Functia verifica daca lista e vida
	*/
	bool listaVida();

	~Lista(void);
};

