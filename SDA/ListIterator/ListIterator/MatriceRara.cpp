#include "MatriceRara.h"
#include <iostream>


MatriceRara::MatriceRara()
{
	//adaug automat cateva case la pornirea aplicatiei
	this->adaugaMatrice(TElement(0, 0, 15));
	this->adaugaMatrice(TElement(0, 1, 14));
	this->adaugaMatrice(TElement(1, 1, 13));
	this->adaugaMatrice(TElement(1, 2, 12));
	this->adaugaMatrice(TElement(1, 4, 13));
	this->adaugaMatrice(TElement(1, 3, 10));
	this->adaugaMatrice(TElement(2, 2, 10));
	this->adaugaMatrice(TElement(2, 3, 11));
	this->adaugaMatrice(TElement(3, 1, 12));
	this->adaugaMatrice(TElement(3, 2, 14));
	this->adaugaMatrice(TElement(4, 2, 11));
	this->adaugaMatrice(TElement(4, 3, 15));
	this->adaugaMatrice(TElement(4, 4, 12));
	this->adaugaMatrice(TElement(5, 2, 17));
	this->adaugaMatrice(TElement(5, 4, 14));
	this->adaugaMatrice(TElement(5, 5, 20));
	this->adaugaMatrice(TElement(6,5,40));
	this->adaugaMatrice(TElement(6,6,30));
	this->adaugaMatrice(TElement(6,6,15));
	this->adaugaMatrice(TElement(7,6,2));
	this->adaugaMatrice(TElement(7,7,12));
	
}



void MatriceRara::adaugaMatrice(TElement element) {

	if (element.getValoare() == 0)
	{
		return;
	}
	
	//daca lista este vida se foloseste functia adauga care adauga la final
	if (lista.listaVida() == true)
		lista.adauga(element);
	else {
		//in caz contrar se cauta pozitia pe care trebuie inserat elementul pentru ca lista sa fie ordonata lexicografic
		TElement elementAnterior = cauta(element);
		//si se foloseste functia adaugaDupa din clasa lista
		lista.adaugaDupa(elementAnterior, element);
	}
}



int MatriceRara::getValoare(int linie, int coloana) {
	for (int i = lista.prim; i<lista.dimensiune; i++)
		if (lista.ListaD[i].data.getLinie() == linie && lista.ListaD[i].data.getColoana() == coloana)
			return lista.ListaD[i].data.getValoare();
	return 0;
}



TElement MatriceRara::cauta(TElement element) {
	//atributele lui element
	int linie = element.getLinie();
	int coloana = element.getColoana();
	int valoare = this->getValoare(linie, coloana);
	//atributele elementului anterior lui element
	int linieNoua = 0;
	int coloanaNoua = 0;
	int valoareNoua = 0;
	//variabile pt deplasare in matrice
	int linieV, coloanaV;
	for (linieV = 0; linieV < lista.dimensiune; linieV++) {
		for (coloanaV = 0; coloanaV<lista.dimensiune; coloanaV++) {
			//in momentul in care gasim linia si coloana corespunzatoare elementului ce trebuie inserat vom avea in linieNoua coloanaNoua valoareNoua 
			//informatiile despre elementul anterior elementului element
			if (coloanaV == coloana && linieV == linie) return TElement(linieNoua, coloanaNoua, valoareNoua);
			else {
				//se va retine tot timpul ultima valoare gasita
				if (this->getValoare(linieV, coloanaV) != 0) {
					linieNoua = linieV;
					coloanaNoua = coloanaV;
					valoareNoua = this->getValoare(linieV, coloanaV);
				}
			}
		}
	}
}
int MatriceRara::cautareSeparata(TElement e)
{
	//se creeaza un iterator
	Iterator* i;
	i = this->Itr();
	int j;
	while (i->valid())
	{
		//se verifica existenta unei linii si a unei coloane
		TElement el = lista.ListaD[i->curent].data;
		i->urmator();
		if (el.getLinie() == e.getLinie() && el.getColoana() == e.getColoana())
			//se returneaza de aceasta data 1 daca exista
			return 1;
	}
	//0 in caz contrar
	return 0;
}
int MatriceRara::getNrLinii()
{
	Iterator *i;
	i = this->Itr();
	int j;
	int maxL = 0;
	TElement e = lista.ListaD[i->curent].data;
	for (j = 0; j < lista.dimensiune; j++)
	{
		if (e.getLinie() > maxL)
			maxL = e.getLinie();
		i->urmator();
		e = lista.ListaD[i->curent].data;
	}
	return maxL;
}

int MatriceRara::getNrColoane()
{
	Iterator *i;
	i = this->Itr();
	int j;
	int maxC = 0;
	TElement e = lista.ListaD[i->curent].data;
	for (j = 0; j < lista.dimensiune; j++)
	{
		if (e.getColoana() > maxC)
			maxC = e.getLinie();
		i->urmator();
		e = lista.ListaD[i->curent].data;
	}
	return maxC;
}

void MatriceRara::afisareMatrice() {
	//se creeaza iterator pentru a putea parcurge lista
	Iterator *i;
	i = this->Itr();
	int j, k;
	int lastC;
	int lastL;
	//se ia elementul curent (care este pe pozitia  0 in momentul initial)
	TElement e = lista.ListaD[i->curent].data;
	for (j = 0; j < 7; j++)
	{
		for (k = 0; k < 7; k++)
		{
			
			if (e.getLinie() == j && e.getColoana() == k)
			{
				std::cout << e.getValoare() << " ";
				i->urmator();
				e = lista.ListaD[i->curent].data;
			}
			else
				std::cout << "x  ";
		}
		std::cout << std::endl;
	}
		
	
}




void MatriceRara::stergeMatrice(TElement element) {
	lista.sterge(element);
}



Iterator* MatriceRara::Itr() {
	//se returneaza un iterator
	return new Iterator(this);
}
//destructor default
MatriceRara::~MatriceRara(void)
{
}
