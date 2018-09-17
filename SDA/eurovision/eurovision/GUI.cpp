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

#include<string>
#include<sstream>

void GUI::initComps() {

	QHBoxLayout* layout = new QHBoxLayout{ this };



	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	//list
	this->lstcountries = new QListWidget{};
	//set the selection model
	this->lstcountries->setSelectionMode(QAbstractItemView::SingleSelection);

	//player data
	QWidget* countryDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ countryDataWidget };
	this->nameEdit = new QLineEdit{};
	this->singerEdit = new QLineEdit{};
	this->titleEdit = new QLineEdit{};
	this->scoreEdit = new QLineEdit{};
	formLayout->addRow("&Country:", nameEdit);
	formLayout->addRow("&Singer:", singerEdit);
	formLayout->addRow("&Title:", titleEdit);
	formLayout->addRow("&Score:", scoreEdit);

	//buttons
	//this->sortButton = new QPushButton("Sort");
	//this->showButton = new QPushButton("Show players");

	leftSide->addWidget(new QLabel{ "Countries " });
	leftSide->addWidget(lstcountries);
	leftSide->addWidget(countryDataWidget);
	//leftSide->addWidget(this->sortButton);
	//leftSide->addWidget(this->showButton);

	layout->addWidget(leftWidget);
	connectSignalsAndSlots();
}

void GUI::connectSignalsAndSlots()
{

	QObject::connect(this->lstcountries, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	//QObject::connect(this->sortButton, SIGNAL(clicked()), this, SLOT(sortPlayers()));
	//QObject::connect(this->showButton, SIGNAL(clicked()), this, SLOT(showPlayers()));
}

void GUI::reloadList(vector<country> countries)
{
	lstcountries->clear();

	for (auto& c : countries)
	{
		stringstream ss;
		ss << c.getScore();
		string str = ss.str();
		QString itemInList = QString::fromStdString(c.getName() + " - " + str);
		this->lstcountries->addItem(itemInList);

	}
}
int GUI::getRepoListSelectedIndex()
{
	if (this->lstcountries->count() == 0)
		return -1;

	//get selected index
	QModelIndexList index = this->lstcountries->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->singerEdit->clear();
		this->titleEdit->clear();
		this->scoreEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void GUI::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	vector<country> countries = this->ctr.getRepo().getCountries();
	if (idx >= countries.size())
		return;
	country c = countries[idx];

	this->nameEdit->setText(QString::fromStdString(c.getName()));
	this->singerEdit->setText(QString::fromStdString(c.getSinger()));
	stringstream ss;
	ss << c.getScore();
	string str = ss.str();
	this->titleEdit->setText(QString::fromStdString(c.getTitle()));
	this->scoreEdit->setText(QString::fromStdString(str));

}

