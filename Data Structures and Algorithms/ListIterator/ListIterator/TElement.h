#pragma once
class TElement
{
private:
	int linie;
	int coloana;
	int valoare;

public:
	TElement(void);
	TElement(int, int, int);

	bool operator!=(TElement& p) {
		return this->valoare != p.getValoare() || this->linie != p.getLinie() || this->coloana != p.getColoana();
	}
	bool operator==(TElement& p) {
		return !(this->valoare != p.getValoare() || this->linie != p.getLinie() || this->coloana != p.getColoana());
	}
	/*
	Functia returneaza linia unui element 
	*/
	int getLinie();
	/*
	Functia returneaza coloana unui element
	*/
	int getColoana();
	/*
	Functia returneaza valoarea unui element
	*/
	int getValoare();
	/*
	Functia seteaza linia elementului cu o noua valoare
	*/
	void setLinie(int val);
	/*
	Functia seteaza coloana elementului cu o noua valoare
	*/
	void setColoana(int val);
	/*
	Functia seteaza valoarea elementului cu o noua valoare
	*/
	void setValoare(int val);
	

	~TElement(void);
};

