#pragma once
#include<vector>
#include "Student.h"
#include "Teacher.h"
#include"Observable.h"
using namespace std;

class Repository: public Observable
{
public:
	Repository();
	vector<Student> getStudents() { sortStudents(); return students; }
	vector<Teacher> getTeachers() { return teachers; }
	void addStudent(Student s);
	void gradeStudent(Student s,double grade,Teacher t);
	void removeStudent(Student s);
	void sortStudents();
	~Repository();
private:
	void readFromFile();
	vector<Student> students;
	vector<Teacher> teachers;
};

