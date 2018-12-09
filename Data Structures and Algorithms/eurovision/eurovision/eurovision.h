#ifndef EUROVISION_H
#define EUROVISION_H

#include <QtWidgets/QMainWindow>
#include "ui_eurovision.h"

class eurovision : public QMainWindow
{
	Q_OBJECT

public:
	eurovision(QWidget *parent = 0);
	~eurovision();
	
private:
	Ui::eurovisionClass ui;
};

#endif // EUROVISION_H
