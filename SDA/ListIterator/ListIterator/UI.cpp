#include "Ui.h"
#include<iostream>
#include "Printesa.h"

using namespace std;

#define scorPrint 100
int ok = 1;


Ui::Ui(void)
{
}

void Ui::afisareUi() {
	mr.afisareMatrice();
}



void Ui::adaugaUi() {
	int linie, coloana, valoare;
	cout << "etaj: "; cin >> linie;
	cout << "camera: "; cin >> coloana;
	cout << "valoare: "; cin >> valoare;
	TElement el(linie - 1, coloana - 1, valoare);
	mr.adaugaMatrice(el);
	cout << "Usa deschisa cu succes!" << endl;
}

void Ui::modificaUi() {
	int linieVeche, coloanaVeche, valoareVeche, valoareNoua;
	cout << "etaj: "; cin >> linieVeche;
	cout << "camera: "; cin >> coloanaVeche;
	cout << "valoarea veche: "; cin >> valoareVeche;
	cout << "valoarea noua: "; cin >> valoareNoua;
	TElement element(linieVeche-1, coloanaVeche-1, valoareVeche);
	TElement el(linieVeche-1, coloanaVeche-1, valoareNoua);
	mr.stergeMatrice(element);
	mr.adaugaMatrice(el);
	
	cout << "Valoarea camerei a fost modificata !" << endl;
}

void Ui::stergeUi() {
	int linie, coloana, valoare;
	cout << "etaj: "; cin >> linie;
	cout << "camera: "; cin >> coloana;
	cout << "valoarea: "; cin >> valoare;
	TElement element(linie-1, coloana-1, valoare);
	mr.stergeMatrice(element);
	cout << "Usa a fost inchisa !" << endl;
}

void Ui::sus()
{
	
	if (print.getLiniePrint() == 0 )
		cout << "Usa inexistenta\n";
	else
	{
		TElement e(print.getLiniePrint() - 1, print.getColoanaPrint()-1, 0);
		if (!mr.cautareSeparata(e))
			cout << "Usa inchisa\n";
		else
		{
			e = mr.cauta(e);
			print.setLinie(print.getLiniePrint() - 1);
			print.setScor(print.getScor() + e.getValoare());
		}
	}
	if (print.getLiniePrint() == printesa.getLiniePrintesa() && print.getColoanaPrint() == printesa.getColoanaPrintesa())
		ok = 0;

}
void Ui::jos()
{

	if (print.getLiniePrint() == 6)
		cout << "Usa inexistenta\n";
	else
	{
		TElement e(print.getLiniePrint() +1, print.getColoanaPrint(), 0);
		
		if (!mr.cautareSeparata(e))
			cout << "Usa inchisa\n";
		else
		{
			e = mr.cauta(e);
			print.setLinie(print.getLiniePrint() +1);
			print.setScor(print.getScor() + e.getValoare());
		}
	}
	if (print.getLiniePrint() == printesa.getLiniePrintesa() && print.getColoanaPrint() == printesa.getColoanaPrintesa())
		ok = 0;

}

void Ui::stanga()
{
	if (print.getColoanaPrint() == 0)
		cout << "Usa inexistenta\n";
	else
	{
		TElement e(print.getLiniePrint() , print.getColoanaPrint() - 1, 0);
		if (!mr.cautareSeparata(e))
			cout << "Usa inchisa\n";
		else
		{
			e = mr.cauta(e);
			print.setColoana(print.getColoanaPrint() -1);
			print.setScor(print.getScor() + e.getValoare());
		}
	}
	if (print.getLiniePrint() == printesa.getLiniePrintesa() && print.getColoanaPrint() == printesa.getColoanaPrintesa())
		ok = 0;
}
void Ui::dreapta()
{
	if (print.getColoanaPrint() == 6)
		cout << "Usa inexistenta\n";
	else
	{
		TElement e(print.getLiniePrint(), print.getColoanaPrint() + 1, 0);
		if (!mr.cautareSeparata(e))
			cout << "Usa inchisa\n";
		else
		{
			e = mr.cauta(e);
			print.setColoana(print.getColoanaPrint() + 1);
			print.setScor(print.getScor() + e.getValoare());
		}
	}
	if (print.getLiniePrint() == printesa.getLiniePrintesa() && print.getColoanaPrint() == printesa.getColoanaPrintesa())
		ok = 0;
}

void Ui::afisareMeniu() {
	cout << "-------Gaseste printesa-------" << endl;
	cout << "Linia pe ca re se afla printul: " << print.getLiniePrint()+1 << endl;
	cout << "Coloana pe care se afla printul: " << print.getColoanaPrint() +1<< endl;
	cout << "Scorul: " << print.getScor() << endl;
	cout << "1. Afisare castel" << endl;
	cout << "5. Deschide o usa" << endl;
	cout << "3. Modifica scorul unei camere" << endl;
	cout << "7. Inchide o usa" << endl;
	cout << "8. Sus" << endl;
	cout << "2. Jos" << endl;
	cout << "4. Stanga" << endl;
	cout << "6. Dreapta" << endl;
	cout << "0. Iesire" << endl;
	cout << "Introduceti optiune: " << endl;
}

void Ui::ruleazaMeniu() {

	

	char optiune[10] = "-1";
	while (ok) {
		
		afisareMeniu();
		cin >> optiune;
		if (strcmp(optiune, "1") == 0)
			afisareUi();
		else if (strcmp(optiune, "5") == 0)
			adaugaUi();
		else if (strcmp(optiune, "3") == 0)
			modificaUi();
		else if (strcmp(optiune, "7") == 0)
			stergeUi();
		else if (strcmp(optiune, "8")==0)
			sus();
		else if (strcmp(optiune, "2")==0)
			jos();
		else if (strcmp(optiune, "4")==0)
			stanga();
		else if (strcmp(optiune, "6")==0)
			dreapta();
		
		else if (strcmp(optiune, "0") == 0)
			break;
		else cout << "Optiunea nu exista" << endl;
	}
	cout << "Jocul s-a termina!" << endl;
	if (print.getScor() >= scorPrint)
		cout << "Ati reusit sa salvati printesa";
	else
		cout << "Nu ati reusit sa salvati printesa";
}


Ui::~Ui(void)
{
}
