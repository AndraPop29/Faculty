#include "controller.h"



using namespace std;

void controller::addPlayer(const std::string& name, const std::string& nat, const std::string& team, int goals)
{
	/*
	try
	{
		this->repository.addPet(name, breed, age, picture);
	}
	catch (repoException& r)
	{
		throw(conException(r.getMessage()));
	}
	catch (validationException& ex)
	{
		throw(conException(ex.getMessage()));
	}
	*/
	this->repository.addPlayer(name, nat, team, goals);
}
