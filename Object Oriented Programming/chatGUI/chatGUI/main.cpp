#include "chatgui.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include"Observable.h"
#include "Observer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository* r = new Repository("messages.txt");
	Controller* c = new Controller(r);
	vector <chatGUI *> windows;
	
	for (auto u : r->getUsers())
	{
		chatGUI* w = new chatGUI(c, u);
		r->attach((Observer*)w);
		w->show();
		windows.push_back(w);
	}
	int ret= a.exec();
	for (auto it : windows)
		delete it;
	delete c;
	delete r;
	return ret;
}
