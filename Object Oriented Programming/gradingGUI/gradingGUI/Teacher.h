#pragma once
#include<string>
#include<vector>
using namespace std;
class Teacher
{
public:
	Teacher();
	Teacher(string name, vector<int> group);
	string getName() { return name; }
	vector<int> getGroups() { return groups; }

	~Teacher();
private:
	string name;
	vector<int> groups;
};

