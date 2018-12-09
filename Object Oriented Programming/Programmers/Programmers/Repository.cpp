#include "Repository.h"
#include<fstream>
#include<string>
#include<algorithm>
#include<sstream>
#include "Observable.h"
Repository::Repository(string filename) 
{
	readFromFile(filename);
}


void Repository::readFromFile(string filename)
{
	ifstream f1("programmers.txt");
	string line;
	while (getline(f1, line)) {
		stringstream get(line);
		vector <string> all;
		string act;
		while (getline(get, act, ',')) {
			all.push_back(act);
		}
		programmers.push_back(Programmer(all[0], stoi(all[1])));
	}

	f1.close();
	ifstream f(filename);

	while (!f.eof())
	{
		Task t;
		f >> t;
		this->tasks.push_back(t);
	}

	f.close();
}
void Repository::addTask(Task t)
{
	tasks.push_back(t);
	notify();

}
void Repository::remove(string d)
{
	for (int i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].getDesc() == d)
			tasks.erase(tasks.begin() + i);
	}
	notify();
}
void Repository::update(Task t)
{
	for (int i = 0; i < tasks.size(); i++)
		if (tasks[i].getDesc() == t.getDesc())
			tasks[i] = t;

	notify();
}
bool myFunction(Task t1, Task t2)
{
	return t1.getStatus() < t2.getStatus();
}

void Repository::sortTasks()
{
	sort(tasks.begin(), tasks.end(), myFunction);
}
vector<Task> Repository::getTasks()
{
	sortTasks();
	return tasks;
}
void Repository::writeToFile()
{
	ofstream f("tasks.txt");
	for (auto it : tasks)
		f << it;
	f.close();
}
Repository::~Repository()
{
}
