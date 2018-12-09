#include "Repository.h"
#include<fstream>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

Repository::Repository()
{
	readFromFile();
}
void Repository::addStudent(Student s)
{
	students.push_back(s);
	notify();
}
void Repository::removeStudent(Student s)
{
	for (int i = 0; i < students.size(); i++)
		if (students[i].getId() == s.getId())
			students.erase(students.begin() + i);
	notify();
}
void Repository::gradeStudent(Student s,double grade, Teacher t)
{
	s.setGrade(grade, t.getName());
	notify();
}
void Repository::readFromFile()
{
	ifstream f("teachers.txt");
	string name;
	int cnt;
	vector<int> gr;
	while (getline(f, name))
	{
		f >> cnt;
		for (int i = 0; i < cnt; ++i)
		{
			int x;
			f >> x;
			gr.push_back(x);
		}
		sort(gr.begin(), gr.end());
		teachers.push_back(Teacher(name, gr));
		gr.clear();
		f.get();
	}
	f.close();
	ifstream f1("students.txt");
	string line;
	while (getline(f1, line))
	{
		stringstream get(line);
		vector<string> all;
		string act;
		while (getline(get, act, ','))
			all.push_back(act);
		students.push_back(Student(stoi(all[0]),all[1],stoi(all[2]),stof(all[3]),all[4]));
		
	}
	f1.close();

	
}
void Repository::sortStudents() {
	sort(students.begin(), students.end(), [](Student a, Student b) {
		return a.getGroup() < b.getGroup() || (a.getGroup() == b.getGroup() && a.getName() < b.getName());
	});
}
Repository::~Repository()
{
}
