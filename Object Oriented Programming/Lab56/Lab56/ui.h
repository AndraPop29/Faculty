#pragma once

#include "controller.h"

class ui
{
private:
	controller con;

public:
	ui(const controller& c) : con(c) {}

	void run();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();
	static void printAdoptionMenu();

	void addPetToRepo();
	void displayAllPets();
	void deletePet();
	void updatePet();
	void addDogsToCat();
	int viewDogs();
	int nextDog();
	int filterDogs();
	void adoptionMenu();
	void adoptDog();
	void viewAdoptList();
};