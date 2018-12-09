#include "gradinggui.h"
#include <QtWidgets/QApplication>
#include "adminagui.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repository *r = new Repository();
	Controller *c = new Controller(r);
	adminaGUI* h=new  adminaGUI(c);
	r->attach((Observer *)h);
	h->show();


	vector <gradingGUI *> windows;
	
	for (auto it : r->getTeachers()) {
		gradingGUI * w = new gradingGUI(c, it);
		r->attach((Observer*)w);
		w->show();
		windows.push_back(w);
	}
	return a.exec();

}
