#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H

#include <QtWidgets/QWidget>
#include "ui_programmers.h"
#include "Controller.h"
#include "Programmer.h"

class Programmers : public QWidget, public Observer
{
	Q_OBJECT

public:
	Programmers(Controller *_c, Programmer _p, QWidget *parent = 0);
	~Programmers();
	void connectSignalsAndSlots();
	int getSelectedItem();
	void update()
	{
		populateList();
	}
public slots:
	void addTask();
	void removeTask();
	void startTask();
	void closeTask();
private:
	Ui::ProgrammersClass ui;
	void populateList();
	Controller *c;
	Programmer p;
};

#endif // PROGRAMMERS_H
