#pragma once
#include "MatriceRara.h"
#include"Printesa.h"
class Ui
{
public:
	Ui(void);

	MatriceRara mr;
	Printesa printesa;
	Priint print;
	void afisareUi();
	void adaugaUi();
	void modificaUi();
	void stergeUi();
	void afisareMeniu();
	void ruleazaMeniu();
	~Ui(void);
	void sus();
	void jos();
	void stanga();
	void dreapta();
};
