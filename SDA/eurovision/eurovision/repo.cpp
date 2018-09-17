#include "repo.h"
#include<string>
#include<fstream>
#include<cassert>



using namespace std;

repo::repo(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}


void repo::readFromFile()
{
	ifstream f(this->filename);

	while (!f.eof())
	{
		country c;
		f >> c;
		if (c.getName() != "")
			this->countries.push_back(c);
	}

	f.close();
}
/*
int repo::nrNat(string nat)
{
	int n = 0;
	for (auto p : this->players)
		if (p.getNat().compare(nat) == 0)
			n++;
	return n;
}
*/

