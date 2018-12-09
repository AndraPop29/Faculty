#ifndef GRADINGGUI_H
#define GRADINGGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_gradinggui.h"
#include "Controller.h"
#include "Teacher.h"

class gradingGUI : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	gradingGUI(Controller* c, Teacher t, QWidget *parent = 0);
	~gradingGUI();
	void update()
	{
		PopulateList();
	}
	int getSelectedItem();
	void connectS();
public slots:
void gradeStudent();
private:
	Ui::gradingGUIClass ui;
	void PopulateList();
	Teacher t;
	Controller *c;

};

#endif // GRADINGGUI_H
