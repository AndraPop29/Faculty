#pragma once
#include "pet.h"
#include "dynVector.h"
class repo
{
private:
	dynVector<pet> pets;
	std::string filename;


public:
	/*
	Constructor with parameters.
	Initializes an object of type repository, by reading data from the given file.
	*/
	repo(const std::string& filename);
	/*
	Adds a dog to the database
	Input: p,of type pet
	Output:-
	*/
	void addPet(const pet& p);
	/*
	Deletes a dog from the database
	Input:name- name of the dog
	Output:1-if successful
	       0-otherwise
	*/
	int deletePet(const std::string& name);
	//Getter for position of a dog
	int getPos(const std::string& name);
	//Getter for the number of pets in the database
	int getRepoSize();
	void testsRepo();
	//Getter for the pets
	dynVector<pet> getPets() { return pets; }


	void readFromFile();
	void writeToFile();
};