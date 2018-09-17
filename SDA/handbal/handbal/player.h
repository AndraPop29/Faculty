#pragma once
#include<string>
using namespace std;
class player
{
private:
	string name;
	string nat;
	string team;
	int goals;
public:
	player();
	player(const string &name, const string &nat, const string &team, int goals);
	string getName(){ return name; }
	string getNat() { return nat; }
	string getTeam() { return team; }
	int getGoals() { return goals; }
	friend std::istream& operator>>(std::istream& is, player &p);
	~player();
};

