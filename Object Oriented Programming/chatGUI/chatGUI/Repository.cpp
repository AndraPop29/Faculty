#include "Repository.h"
#include<fstream>
#include<sstream>
#include<string>


Repository::Repository(string filename)
{
	this->filename = filename;
	readFromFile();
}
void Repository::addMessage(Message mes)
{
	messages.push_back(mes);
	notify();
}

void Repository::readFromFile()
{
	ifstream f1("Users.txt");
	string line;
	while (getline(f1, line)) {
		stringstream get(line);
		vector <string> all;
		string act;
		while (getline(get, act, ',')) {
			all.push_back(act);
		}
		users.push_back(User(all[0], stoi(all[1])));
	}

	f1.close();

	ifstream f2(filename);
	string line2;
	while (getline(f2, line2)) {
		stringstream get(line2);
		vector <string> all;
		string act1;
		while (getline(get, act1, '|')) {
			all.push_back(act1);
		}
		if (all.size() == 0)
			break;
		messages.push_back(Message(all[0], stoi(all[1])));
	}

	f2.close();
	
}
void Repository::writeToFile()
{
	ofstream f(filename);
	for (auto m:messages)
		f << m.getText() << "|" << m.getUser() << "\n";
	f.close();
}

string Repository::getName(int id)
{
	for (auto u : users)
		if (u.getId() == id)
			return u.getName();
	return "";
}
void Repository::clearMessages()
{
	//for (int i = 0; i < messages.size(); i++)
		//messages.erase(messages.begin() + i);
	messages.clear();
}
Repository::~Repository()
{
}
