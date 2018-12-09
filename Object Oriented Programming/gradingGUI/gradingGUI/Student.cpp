#include "Student.h"



Student::Student() : id(-1), name(""), group(-1), grade(0) {}

Student::Student(int id, string name, int group, double grade,string teacher)
{
	this->id = id;
	this->name = name;
	this->group = group;
	this->grade = grade;
	this->teacher = teacher;
}
void Student::setGrade(int _g,string _t)
{
	this->grade = _g;
	this->teacher = _t;
}
string Student::toString() const {
	return to_string(id) + "," + name + "," + to_string(group) +
		"," + to_string(grade) + "," + teacher;
}

Student::~Student()
{
}
