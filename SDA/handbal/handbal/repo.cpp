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

void repo::addPlayer(std::string name, std::string nat , string team, int goals)
{
	/*
	int pos = this->getPos(name);

	pet p{ name,breed, age,photo };
	if (pos != -1)
	{
		throw(repoException("The pet already exists! "));
	}

	petValidator vali;
	vali.validate(p);
	*/
	player p{ name,nat,team,goals };
	players.push_back(p);
	//this->writeToFile();


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
