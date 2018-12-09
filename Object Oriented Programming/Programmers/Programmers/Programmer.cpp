#include "Programmer.h"
#include<vector>
#include<sstream>
using namespace std;


Programmer::Programmer(): name(""), id(-1){}

Programmer::Programmer(string name, int id)
{
	this->name = name;
	this->id = id;
}


Programmer::~Programmer()
{
}
