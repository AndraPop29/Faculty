#pragma once
#ifndef GUI_H
#define GUI_H


#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "qwidget.h"
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "controller.h"
#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>


class GUI : public QWidget {
	Q_OBJECT
private:
	void initComps();

	void reloadList(vector<player> pets);
	controller& ctr;
	QListWidget* lstplayers;
	
	//QPushButton* btnUpdate;
	QPushButton* showButton;
	QPushButton* sortButton;
	QLineEdit* nameEdit;
	QLineEdit* natEdit;
	QLineEdit* teamEdit;
	QLineEdit* goalsEdit;
	

	int getRepoListSelectedIndex();
	void connectSignalsAndSlots();
public:
	

	GUI(controller& c) : ctr{ c } {
		initComps();
		reloadList(c.getRepo().getPlayers());
	}


private slots:

//when an item in the list is selected the text boxes get filled with the item's information
	void listItemChanged();
	void sortPlayers();
	void showPlayers();
};


#endif // GUI_H

