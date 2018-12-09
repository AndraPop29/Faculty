#include "Task.h"
#include<string>
#include<vector>
#include<sstream>

Task::Task() : desc(""), status(""), prog(-1){}

Task::Task(string d,string s, int p)
{
	this->desc = d;
	this->status = s;
	this->prog = p;
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
std::istream& operator>>(std::istream &is, Task &t)
{
	string line;
	std::getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 3)
		return is;
	t.desc = tokens[0];
	t.prog = atoi(tokens[1].c_str());
	t.status = tokens[2];


	return is;

}
std::ostream& operator<<(std::ostream &os,Task &t)
{
	os << t.desc << "," << t.prog << "," << t.status <<"\n";
	return os;
}

Task::~Task()
{
}
