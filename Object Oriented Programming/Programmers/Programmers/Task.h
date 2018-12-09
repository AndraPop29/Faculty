#pragma once
#include<string>
using namespace std;

class Task
{
private:
	string desc, status;
	int prog;
public:
	Task();
	Task(string d, string s, int p);
	string getDesc() {
		return desc;
	}
	string getStatus() {
		return status;
	}
	int getProg(){
		return prog;
	}
	void setProg(int p) {
		prog = p;
	}
	void setStatus(string s) {
		status = s;
	}
	friend std::istream& operator>>(std::istream& is, Task &t);
	friend std::ostream& operator<<(std::ostream &os, Task &t);
	~Task();
};

