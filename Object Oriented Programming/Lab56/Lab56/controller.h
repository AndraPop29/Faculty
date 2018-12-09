#pragma once

#include "repo.h"
#include "catalog.h"
class controller
{
private:
	repo repository;
	catalog Catalog;

public:
	controller(const repo& r): repository(r) {}
	//default constructor for controller
	repo getRepo() const { return repository; }
	//getter for the repository
	catalog getCat() const { return Catalog; }
	int addPetToRepo(const std::string& name, const std::string& breed, int age, const std::string& picture);
	/*
	Adds a dog to the database
	Input: name,breed,age and picture
	Output:1, if successful
	0, otherwise
	*/
	int deletePetFromRepo(const std::string& name);
	/*
	Deletes a dog from the database
	Input:name- name of the dog
	Output:1-if successful
	0-otherwise
	*/
	void clearCat();
	/*
	Clears the catalog
	*/
	void addPetToCat(const pet& p);
	/*
	Adds a pet to the catalog
	Input: p-pet
	Output:-
	*/
	void openCat();
	//Opens the catalog
	void nextPet();
	//Shows the next pet
	int filterD(std::string b, int a);
	//Filters by breed and age
	//Input: b-breed, a-age
	//Output: 1/0
	void sortPets();
	//Sorts the list of pets
	void testCont();
	void addToList(const pet& p);
	//Adds a pet to the adoption list
	//Input:p-pet
	//Output:-
};