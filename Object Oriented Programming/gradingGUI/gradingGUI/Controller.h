#pragma once
#include "Repository.h"
class Controller
{
public:
	Controller();
	Controller(Repository *r);
	void addStudent(Student s);
	void removeStudent(Student s);
	void gradeStudent(Student s,double grade, Teacher t);
	vector<Student> getStudents() { return r->getStudents(); }
	vector<Teacher> getTeachers() { return r->getTeachers(); }
	~Controller();
private:
	Repository *r;
};

