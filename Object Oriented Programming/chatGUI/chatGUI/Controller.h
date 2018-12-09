#pragma once
#include "Repository.h"
class conException
{
private:
	string mess;
public:
	conException(string message)
	{
		this->mess = message;
	}
	string getMes()
	{
		return this->mess;
	}
};
class Controller
{
private:
	Repository* r;

	
public:
	Controller(Repository* repo) :r(repo) {}
	void addMessage(string m, int id);
	void clearMessages();
	void writeToFile();
	string getName(int id);
	vector<Message> getMessages() { return r->getMessages(); }
	vector<User> getUsers() { return r->getUsers(); }
	~Controller();
};

