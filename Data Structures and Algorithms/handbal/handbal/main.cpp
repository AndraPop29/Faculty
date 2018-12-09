#include "GUI.h"
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
#include "player.h"

#include <QtWidgets/QApplication>
#include "GUI.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	repo r{ "players.txt" };
	controller c(r);
	QApplication a{ argc,argv };
	GUI gui{ c };
	gui.show();

	return a.exec();

	
}
