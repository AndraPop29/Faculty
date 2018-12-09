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
	this->lstplayers = new QListWidget{};
	//set the selection model
	this->lstplayers->setSelectionMode(QAbstractItemView::SingleSelection);

	//player data
	QWidget* playerDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ playerDataWidget };
	this->nameEdit = new QLineEdit{};
	this->natEdit = new QLineEdit{};
	this->teamEdit = new QLineEdit{};
	this->goalsEdit = new QLineEdit{};
	formLayout->addRow("&Name:", nameEdit);
	formLayout->addRow("&Nationality:", natEdit);
	formLayout->addRow("&Team:", teamEdit);
	formLayout->addRow("&Goals:", goalsEdit);

	//buttons
	this->sortButton = new QPushButton("Sort");
	this->showButton = new QPushButton("Show players");

	leftSide->addWidget(new QLabel{ "Players " });
	leftSide->addWidget(lstplayers);
	leftSide->addWidget(playerDataWidget);
	leftSide->addWidget(this->sortButton);
	leftSide->addWidget(this->showButton);

	layout->addWidget(leftWidget);
	connectSignalsAndSlots();
}

void GUI::connectSignalsAndSlots()
{
	
	QObject::connect(this->lstplayers, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->sortButton, SIGNAL(clicked()), this, SLOT(sortPlayers()));
	QObject::connect(this->showButton, SIGNAL(clicked()), this, SLOT(showPlayers()));
}

void GUI::reloadList(vector<player> players)
{
	lstplayers->clear();

	for (auto& p : players)
	{
	
		QString itemInList = QString::fromStdString(p.getName() + " - " + p.getTeam());
		this->lstplayers->addItem(itemInList);

	}
}
int GUI::getRepoListSelectedIndex()
{
	if (this->lstplayers->count() == 0)
		return -1;

	//get selected index
	QModelIndexList index = this->lstplayers->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->natEdit->clear();
		this->teamEdit->clear();
		this->goalsEdit->clear();
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

	vector<player> players = this->ctr.getRepo().getPlayers();
	if (idx >= players.size())
		return;
	player p = players[idx];

	this->nameEdit->setText(QString::fromStdString(p.getName()));
	this->natEdit->setText(QString::fromStdString(p.getNat()));
	stringstream ss;
	ss << p.getGoals();
	string str = ss.str();
	this->teamEdit->setText(QString::fromStdString(p.getTeam()));
	this->goalsEdit->setText(QString::fromStdString(str));

}
void GUI::sortPlayers()
{
	
	vector<player> p=this->ctr.sortPlayers();
	this->reloadList(p);
}
void GUI::showPlayers()
{
	string nat = this->natEdit->text().toStdString();
	int nr = this->ctr.nrNat(nat);
	stringstream ss;
	ss << nr;
	string str = ss.str();
	this->nameEdit->setText(QString::fromStdString(str));
}