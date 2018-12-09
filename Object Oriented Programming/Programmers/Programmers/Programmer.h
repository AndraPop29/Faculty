#pragma once
#include<string>
using namespace std;

class Programmer
{
private:
	string name;
	int id;
public:
	Programmer();
	Programmer(string name, int id);
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	~Programmer();
};

