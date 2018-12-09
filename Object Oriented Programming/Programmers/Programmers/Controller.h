#pragma once
#include "Repository.h"

class conException
{
private:
	string message;
public:
	conException(std::string message)
	{
		this->message = message;
	}
	std::string getMessage() const
	{

		return this->message;
	}
};
class Controller
{
private:
	Repository* repo;
public:
	Controller(Repository* r) : repo(r) {};
	string getP(int id);
	void addTask(string desc);
	void removeT(Task t);
	
	void startTask(Task t,int id);
	void closeTask(Task t, int id);
	void writeToFile();
	vector<Task> getTasks();
	
	~Controller();
};

