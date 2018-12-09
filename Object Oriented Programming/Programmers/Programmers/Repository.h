#pragma once
#include<vector>
#include "Programmer.h"
#include "Task.h"
#include "Observable.h"

using namespace std;

class Repository: public Observable
{
private:
	vector<Programmer> programmers;
	vector<Task> tasks;
public:
	Repository(string filename="tasks.txt");

	vector<Programmer> getProgrammers()
	{
		return programmers;
	}
	vector<Task> getTasks();
	void addTask(Task t);
	void update(Task t);
	void remove(string d);
	void sortTasks();
	void readFromFile(string filename);
	void writeToFile();
	~Repository();
};

