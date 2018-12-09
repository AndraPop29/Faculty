#include "controller.h"
#include<cassert>
#include<iostream>
using namespace std;
int controller::addPetToRepo(const std::string& name, const std::string& breed, int age, const std::string& picture)
{
	int pos = this->repository.getPos(name);
	if (pos != -1)
		return 0;
	pet p{ name, breed, age, picture };
	this->repository.addPet(p);
	return 1;
}

int controller::deletePetFromRepo(const std::string& name)
{
	//pet p{ name,breed,age,picture };
	int result = this->repository.deletePet(name);
	return result;
}

void controller::addPetToCat(const pet& p)
{
	this->Catalog.add(p);
}

void controller::openCat()
{
	this->Catalog.view();
}

void controller::addToList(const pet& p)
{
	this->Catalog.addToList(p);
}
void controller::nextPet()
{
	this->Catalog.next();
}

int controller::filterD(std::string b, int a)
{
	int ok = 0;
	dynVector<pet> v = this->getRepo().getPets();
	for (int i = 0; i < v.getSize(); i++)
	{
		if (v[i].getBreed() == b && v[i].getAge() < a)
		{
			ok = 1;
			this->addPetToCat(v[i]);
		}
	}
	return ok;
}
void controller::clearCat()
{
	this->Catalog.clear();
}
void controller::sortPets()
{
	dynVector<pet> &v = this->getRepo().getPets();
	int s;
	
	do
	{
		s = 0;
		for (int i = 0; i < v.getSize()-1;i++)
			if (v[i].getAge()>v[i + 1].getAge())
			{
				pet a=v[i];
				v[i] = v[i + 1];
				v[i + 1] = a;
				s = 1;
			
			}

	} while (s != 0);
	this->getRepo().getPets() = v;
}

void controller::testCont()
{

	pet p{ "Pufoshenie","Poodle",4,"1.jpg" };

	
	//tests for adding
	this->addPetToRepo("Pufoshenie", "Poodle", 4, "1.jpg");
	assert(this->repository.getRepoSize() == 1);

	this->addPetToRepo("Pufoshenie", "Poodle", 4, "1.jpg");
	assert(this->repository.getRepoSize() == 1);

	//tests for catalog
	this->addPetToCat(p);
	assert(this->Catalog.getDogs().getSize() == 1);

	this->addToList(p);
	assert(this->Catalog.getList().getSize() == 1);

	this->clearCat();
	assert(this->Catalog.getDogs().getSize() == 0);

	this->filterD("Poodle", 10);
	assert(this->Catalog.getDogs().getSize() == 1);
	
	this->clearCat();

	//tests for deleting
	this->deletePetFromRepo("Pufoshenie");
	assert(this->repository.getRepoSize() == 0);

	this->deletePetFromRepo("Pufoshenie");
	assert(this->repository.getRepoSize() == 0);



}

