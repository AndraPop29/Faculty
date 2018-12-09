#pragma once
class Printesa
{
	int lin=4;
	int col=2;
public:

	int getLiniePrintesa()
	{
		return lin;
	}
	int getColoanaPrintesa()
	{
		return col;
	}
};

class Priint
{
public:

	int lin=0;
	int col=0;
	int scor = 0;

	int getLiniePrint()
	{
		return lin;
	}
	int getColoanaPrint()
	{
		return col;
	}
	int getScor()
	{
		return scor;
	}
	void setLinie(int l)
	{
		lin = l;
	}
	void setColoana(int c)
	{
		col = c;
	}
	void setScor(int s)
	{
		scor = s;
	}
};