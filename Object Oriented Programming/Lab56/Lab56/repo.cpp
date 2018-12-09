#include "repo.h"
#include<string>
#include<fstream>
#include<cassert>
#include "utils.h"

using namespace std;

repo::repo(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void repo::addPet(const pet& p)
{
	//this->pets.add(p);
	this->pets + p;
	this->writeToFile();

}

int repo::getPos(const std::string& n)
{
	pet* petsInVector = this->pets.getAllElems();
	if (petsInVector == NULL)
		return -1;

	for (int i = 0; i < this->pets.getSize(); i++)
	{
		pet p1 = petsInVector[i];
		if (p1.getName()== n)
			return i;
	}
	return -1;
}

int repo::deletePet(const std::string& name)
{
	int pos = getPos(name);
	if (pos == -1)
		return 0;
	else
	{
		this->pets.deleteE(pos);
		this->writeToFile();
	}
	return 1;
}


void repo::readFromFile()
{
	ifstream f(this->filename);
	string line;
	while (getline(f, line))
	{
		string tokens[20];
		int length = 0;
		tokenize(line, '|', tokens, length);
		if (length != 4)
			continue;
		int age=atoi(tokens[2].c_str());
		pet p(tokens[0], tokens[1], age, tokens[3]);
		//this->pets.add(p);
		this->pets + p;
	}

	//f.close();
}

int repo::getRepoSize()
{
	return this->pets.getSize();
}

void repo::writeToFile()
{
	ofstream f(this->filename);
	pet* elems = this->pets.getAllElems();
	for (int i = 0; i < this->pets.getSize(); i++)
	{
		pet currentPet = elems[i];
		f << currentPet.getName() << " | " << currentPet.getBreed() << " | " << currentPet.getAge() << " | " << currentPet.getPhoto() << endl;
	}
	f.close();
}

void repo::testsRepo()
{
	//this->pets.testVector();
	pet p{ "Pufoshenie","Poodle",4,"1.jpg" };

	//tests for adding
	int l = this->pets.getSize();
	this->addPet(p);
	assert(this->pets.getSize() == l+1);

	//test for position getter
	assert(this->getPos(p.getName()) == 0);
    
	//tests for deleting
	int val = this->deletePet(p.getName());
	assert(this->pets.getSize()==l);

	int val2 = this->deletePet("Andra");
	assert(val2 == 0);
	assert(this->pets.getSize() == l);
}