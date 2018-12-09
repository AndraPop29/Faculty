#include "Controller.h"



Controller::Controller(Repository* _r): r(_r)
{
}
void Controller::addStudent(Student s)
{
	r->addStudent(s);
}
void Controller::removeStudent(Student s)
{
	r->removeStudent(s);
}
void Controller::gradeStudent(Student s, double grade, Teacher t)
{
	r->gradeStudent(s,grade,t);
}
Controller::~Controller()
{
}
