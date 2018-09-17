#include "repo.h"



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

void repo::addPlayer(std::string name, std::string nat, string team, int goals)
{
	
	player p{ name,nat,team,goals };
	players.push_back(p);



}
void repo::readFromFile()
{
	ifstream f(this->filename);

	while (!f.eof())
	{
		player p;
		f >> p;
		if (p.getName() != "")
			this->players.push_back(p);
	}

	f.close();
}
int repo::nrNat(string nat)
{
	int n = 0;
	for (auto p : this->players)
		if (p.getNat().compare(nat) == 0)
			n++;
	return n;
}

