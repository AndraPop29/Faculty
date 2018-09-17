#include "Lista.h"
#include<iostream>

using namespace std;

Lista::Lista()
{
	int i;
	this->dimensiune = dim;

	for (i = 0; i<this->dimensiune; i++) {
		this->ListaD[i].data = TElement();
		this->ListaD[i].urmator = NULL;
		this->ListaD[i].precedent = NULL;
	}
	this->prim = 0;
	this->primLiber = 0;
	this->ultim = 0;
}



void Lista::cautaPrimLiber() {
	int i;
	for (i = this->prim; i <= this->dimensiune; i++) {
		if (ListaD[i].data == TElement(0, 0, 0)) {
			this->primLiber = i;
			break;

		}
	}
}


void Lista::adauga(TElement elem) {
	//se creeaza un nod
	struct TNod nou;
	nou.data = elem;
	nou.urmator = NULL;
	//se verifica daca mai exista elemente in lista,daca nu se adauga la final
	if (this->prim == NULL) {	
		nou.precedent = NULL;
		this->prim = 1;
		this->primLiber = 2;
		ListaD[1] = nou;
	}
	//daca lista nu este vida se adauga elementul dupa primul liber
	else
	{
		ListaD[this->primLiber - 1].urmator = primLiber;
		nou.precedent = this->primLiber - 1;
		ListaD[this->primLiber] = nou;
		primLiber++;
	}
}



void Lista::adaugaDupa(TElement element, TElement elNou) {
	//cautam pozitia elementului dupa care vrem sa inseram
	int pozitie = prim;
	while (ListaD[pozitie].data != element)
		pozitie = ListaD[pozitie].urmator;

	//inseram noul element
	Lista::cautaPrimLiber();
	struct TNod nou;
	nou.data = elNou;
	nou.precedent = pozitie;
	nou.urmator = ListaD[pozitie].urmator;
	ListaD[ListaD[pozitie].urmator].precedent = this->primLiber;
	ListaD[this->primLiber] = nou;
	ListaD[pozitie].urmator = this->primLiber;
	this->ultim = primLiber - 1;
}



void Lista::sterge(TElement element) {
	//cautam pozitia elementului pe care vrem sa-l stergem
	int pozitie = this->prim;
	while (ListaD[pozitie].data != element)
		pozitie = ListaD[pozitie].urmator;

	if (pozitie == this->prim) 
	{ //daca elementul pe care vrem sa-l stergem se afla pe prima pozitie(este primul in lista)
		this->prim = this->prim + 1;
		ListaD[ListaD[pozitie].urmator].precedent = 0;
		ListaD[pozitie].data = TElement(0, 0, 0);
	}
	else if (pozitie == ultim) {	
		//daca elementul pe care vrem sa-l stergem se afla pe ultima pozitie(este ultimul din lista)
		ListaD[ListaD[pozitie].precedent].urmator = 0;
		ListaD[pozitie].data = TElement(0, 0, 0);
	}
	else {
		//daca elementul pe care vrem sa-l stergem se afla in interiorul listei
		ListaD[ListaD[pozitie].precedent].urmator = ListaD[pozitie].urmator;
		ListaD[ListaD[pozitie].urmator].precedent = ListaD[pozitie].precedent;
		ListaD[pozitie].data = TElement(0, 0, 0);

	}
	Lista::cautaPrimLiber();
}


bool Lista::listaVida() {
	bool vida = true;
	for (int i = prim; i<this->dimensiune; i++) {
		if (ListaD[i].data != TElement(0, 0, 0))
			vida = false;
	}
	return vida;
}
Lista::~Lista(void)
{
}
