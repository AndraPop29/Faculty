#include "programmers.h"
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository *r = new Repository();
	Controller *c = new Controller(r);
	vector <Programmers *> windows;
	for (auto it : r->getProgrammers()) {
		Programmers * w = new Programmers(c, it);
		r->attach((Observer*)w);
		w->show();
		windows.push_back(w);
	}

	return a.exec();
}
