#include "GUI.h"


#include "QtWidgets\qListwidget.h"
#include "QtWidgets\QHBoxLayout"
#include "QtWidgets\QVBoxLayout"
#include "QtWidgets\QPushButton"
#include "QtWidgets\QFormLayout"
#include "QtWidgets\QLabel"
#include "QtWidgets\qmessagebox.h"
#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include<string>
#include<sstream>

GUI::GUI(controller& c, QWidget *parent) : ctr{ c }, QWidget{ parent }
{
	this->initGUI();
	//this->currentSongsInRepoList = this->ctrl.getAllSongs();
	//his->populateRepoList();
}
void GUI::initComps() {

	QHBoxLayout* layout = new QHBoxLayout{ this };

	//Prepare left side components-vertical layout with:
	//-list
	//-form layout with song data
	//-grid layout with buttons: add,delete,update,filter

	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	//list
	this->lstplayers = new QListWidget{};
	//set the selection model
	this->lstplayers->setSelectionMode(QAbstractItemView::SingleSelection);

	//pet data
	QWidget* playerDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ playerDataWidget };
	this->nameEdit = new QLineEdit{};
	this->natEdit = new QLineEdit{};
	this->teamEdit = new QLineEdit{};
	this->goalsEdit = new QLineEdit{};
	formLayout->addRow("&Name:", nameEdit);
	formLayout->addRow("&Nationality:", breedEdit);
	formLayout->addRow("&Team:", ageEdit);
	formLayout->addRow("&Goals:", linkEdit);


	layout->addWidget(leftWidget);
}
