#include "eurovision.h"
#include <QtWidgets/QApplication>

#include "repo.h"
#include "controller.h"
#include <crtdbg.h>
#include <Windows.h>
#include<iostream>
#include <algorithm>
#include <iterator>

#include<cstring>
#include<sstream>
#include "country.h"

#include <QtWidgets/QApplication>
#include "GUI.h"
//#include "tests.h"

int main(int argc, char *argv[])
{
	//testAll();
	repo r{ "countries.txt" };
	controller c{ r };
	QApplication a(argc, argv);
	GUI gui{ c };
	gui.show();
	return a.exec();


}
