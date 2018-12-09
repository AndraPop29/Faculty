#pragma once

#include<string>
using namespace std;
class country
{
private:
	string name;
	string singer;
	string title;
	int score;
public:
	country();
	country(const string &name, const string &singer, const string &title, int score);
	string getName() { return name; }
	string getSinger() { return singer; }
	string getTitle() { return title; }
	int getScore() { return score; }
	friend std::istream& operator>>(std::istream& is, country &c);

};

