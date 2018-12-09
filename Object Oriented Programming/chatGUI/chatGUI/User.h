#pragma once
#include<string>
using namespace std;

class User
{
private:
	string name;
	int id;
public:
	User();
	User(string name, int id);
	string getName() { return name; }
	int getId() { return id; }
	~User();
};

