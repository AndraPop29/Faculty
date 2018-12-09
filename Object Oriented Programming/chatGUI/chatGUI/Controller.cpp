#include "Controller.h"




string Controller::getName(int id)
{
	return r->getName(id);
}
void Controller::addMessage(string m,int id)
{
	if (m == "")
		throw(conException("Please enter a message!"));
	Message mes{ m,id };
	r->addMessage(mes);

}
void Controller::clearMessages()
{
	r->clearMessages();
}
void Controller::writeToFile()
{
	r->writeToFile();
}
Controller::~Controller()
{
}
