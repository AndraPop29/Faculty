#pragma once
#include "country.h"
#include<vector>
#include<string>
using namespace std;

class repoException
{
public:
	repoException(std::string message)
	{
		this->message = message;
	}
	std::string getMessage() const
	{

		return this->message;
	}
private:
	std::string message;
};
class repo
{
private:
	vector<country> countries;
	std::string filename;


public:

	repo(const std::string& filename);

	//void addCountry(std::string name, std::string nat, std::string team, int goals);


	vector<country> getCountries() { return countries; }
	//int nrNat(string nat);

	void readFromFile();

};



