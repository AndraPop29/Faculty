#include "ui.h"
#include "repo.h"
#include "controller.h"
#include <crtdbg.h>
#include <Windows.h>
#include<iostream>
#include <algorithm>
#include <iterator>
#include "catalog.h"
using namespace std;

int main()
{
	system("color f5");
	pet p1{ "Lisa","Shitzu",4,"http://www.natiuneacanina.ro/adoption/shih-tzu/" };
	pet p2{ "Cookie","Yorkshire",3,"https://www.123rf.com/stock-photo/yorkshire_terrier.html" };
	pet p3{ "Sisu","Labrador",2,"http://www.akc.org/dog-breeds/labrador-retriever/" };
	pet p4{ "Champion","Bulldog",5,"http://petmark.org/Pet/195/Bulldog-Englez.html" };
	pet p5{ "Ghita","Beagle",7,"http://dogtime.com/dog-breeds/beagle" };
	repo r("dogs.txt");
	r.addPet(p1);
	r.addPet(p2);
	r.addPet(p3);
	r.addPet(p4);
	r.addPet(p5);
	repo rTEST("test.txt");
	catalog cat{};
	cat.testCat();
	rTEST.testsRepo();
	controller cTEST(rTEST);
	cTEST.testCont();
	controller c(r);
	ui UI(c);
	UI.run();
	

	return 0;
}