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
	/*
	Constructor with parameters.
	Initializes an object of type repository, by reading data from the given file.
	*/
	repo(const std::string& filename);
	
	void addPlayer(std::string name, std::string nat, std::string team, int goals);

	//void deletePet(const std::string& name);

	//int getPos(const std::string& name);
	
	//int getRepoSize();
	//void testsRepo();
	
	vector<player> getPlayers() { return players; }


	void readFromFile();
	
};

