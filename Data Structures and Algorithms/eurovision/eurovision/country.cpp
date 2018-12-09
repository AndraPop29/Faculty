#include "country.h"
#include<sstream>
#include<vector>

country::country() : name(""), singer(""), title(""), score(0) {}
country::country(const string &name, const string &singer, const string &title, int score)
{
	this->name = name;
	this->singer = singer;
	this->title = title;
	this->score = score;
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
std::istream& operator>>(std::istream &is, country &c)
{
	string line;
	std::getline(is, line);
	vector<string> tokens = tokenize(line, '|');
	if (tokens.size() != 4)
		return is;
	c.name = tokens[0];
	c.singer = tokens[1];
	c.title = tokens[2];
	c.score = atoi(tokens[3].c_str());



	return is;

}

