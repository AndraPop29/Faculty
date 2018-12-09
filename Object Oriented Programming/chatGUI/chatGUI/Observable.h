#pragma once

#include <vector>
#include "Observer.h"

using namespace std;

class Observable
{
public:
	Observable();
	void attach(Observer* ob)
	{
		o.push_back(ob);
	}
	void notify()
	{
		for (auto it : o)
			it->update();
	}
	~Observable();
private:
	vector<Observer*> o;
};

