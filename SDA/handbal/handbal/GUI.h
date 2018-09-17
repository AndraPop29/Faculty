#pragma once
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
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* viewButton;
	QPushButton* nextButton;
	QPushButton* viewAllButton;
	//QPushButton* btnUpdate;
	QPushButton* filterButton;
	QPushButton* adoptPet;
	QLineEdit* nameEdit;
	QLineEdit* natEdit;
	QLineEdit* teamEdit;
	QLineEdit* goalsEdit;
	QListWidget* adoList;

	//int getRepoListSelectedIndex();
	//void connectSignalsAndSlots();
public:
	GUI(controller& c, QWidget *parent = 0);

	//GUI(controller& c) : ctr{ c } {
		//initComps();
		//this->currentPets = this->ctr.getRepo().getPets();
		//reloadList(c.getRepo().getPets());

	}
	/*
private slots:
	
		//when an item in the list is selected the text boxes get filled with the item's information
		void listItemChanged();
		void addNewPet();
		void deletePet();
		void updatePet();
		void filterRepoPets();
		void viewPet();
		void populateList();
		void adoptaPet();
		void nextPet();
		void viewAllD();
		int changeIndex();
	*/
};

