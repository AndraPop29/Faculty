#ifndef ADMINAGUI_H
#define ADMINAGUI_H

#include <QWidget>
#include "ui_adminagui.h"

#include "Controller.h"

class adminaGUI : public QWidget, public Observer
{
	Q_OBJECT

public:
	adminaGUI(Controller *_c,QWidget *parent = Q_NULLPTR);
	void connectSignalsAndSlots();
	int getSelectedItem();
	void update()
	{
		populateList();
	}
	~adminaGUI();

public slots:
	void addStudent();
	void removeStudent();
private:
	void populateList();
	Ui::adminaGUI ui;
	Controller *c;
};

#endif // ADMINAGUI_H
