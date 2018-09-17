#include "player.h"
#include<vector>
#include<sstream>


player::player() : name(""), nat(""), team(""), goals(0) {}
player::player(const string &name, const string &nat, const string &team, int goals)
{
	this->name = name;
	this->nat = nat;
	this->team = team;
	this->goals = goals;
}

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;


}
std::istream& operator>>(std::istream &is, player &p)
{
	string line;
	std::getline(is, line);
	vector<string> tokens = tokenize(line, '|');
	if (tokens.size() != 4)
		return is;
	p.name = tokens[0];
	p.nat = tokens[1];
	p.team = tokens[2];
	p.goals = atoi(tokens[3].c_str());



	return is;

}

