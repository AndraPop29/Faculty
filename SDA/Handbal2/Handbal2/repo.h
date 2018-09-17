#pragma once
#include "player.h"
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
	vector<player> players;
	std::string filename;


public:
	
	repo(const std::string& filename);

	void addPlayer(std::string name, std::string nat, std::string team, int goals);


	vector<player> getPlayers() { return players; }
	int nrNat(string nat);

	void readFromFile();

};


