#pragma once
#include<string>
using namespace std;
class Student
{
public:
	Student();
	Student(int id, string name, int group, double grade,string teacher);
	int getId() { return id; }
	string getName() { return name; }
	int getGroup() { return group; }
	double getGrade() { return grade; }
	string toString() const;
	string getTeach() { return teacher; }
	void setGrade(int g, string teacher);
	inline string humanString() const {
		return name + " - " + to_string(group) + " - " + to_string(grade) + " - " + teacher;
	}
	~Student();
private:
	int id;
	string name,teacher;
	int group;
	double grade;
};

