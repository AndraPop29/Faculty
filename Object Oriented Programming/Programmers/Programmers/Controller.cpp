#include "Controller.h"
#include<algorithm>


string Controller::getP(int id)
{
	for (auto p : repo->getProgrammers())
		if (p.getId() == id)
			return p.getName();
	return "";
}
void Controller::removeT(Task t)
{
	repo->remove(t.getDesc());
}
void Controller::addTask(string desc)
{
	Task t{ desc,"open",-1 };
	repo->addTask(t);
}

void Controller::startTask(Task t,int id)
{
	if (t.getStatus() != "open")
		throw(conException("Task is not open!"));
	t.setStatus("in progress");
	t.setProg(id);
	repo->update(t);
}
vector<Task> Controller::getTasks()
{
	return repo->getTasks();
}
void Controller::closeTask(Task t, int id)
{
	if (t.getStatus()=="in progress" && (t.getProg() == id))
		t.setStatus("closed");
	repo->update(t);
}
void Controller::writeToFile()
{
	repo->writeToFile();
}
Controller::~Controller()
{
}
