#include "programmers.h"
#include "qlistwidget.h"

#include "qmessagebox.h"
Programmers::Programmers(Controller *_c, Programmer _p, QWidget *parent)
	: c(_c), p(_p), QWidget(parent)
{
	ui.setupUi(this);
	QWidget::setWindowTitle(QString::fromStdString(p.getName()));
	connectSignalsAndSlots();
	populateList();
}
void Programmers::connectSignalsAndSlots()
{
	QObject::connect(ui.AddBut, SIGNAL(clicked()), this, SLOT(addTask()));
	QObject::connect(ui.removeBut, SIGNAL(clicked()), this, SLOT(removeTask()));
	QObject::connect(ui.startBut, SIGNAL(clicked()), this, SLOT(startTask()));
	QObject::connect(ui.closeBut, SIGNAL(clicked()), this, SLOT(closeTask()));

}
void Programmers::populateList() {
	ui.listTasks->clear();
	//vector<Task> all=c->sortTasks();
	for (auto it : c->getTasks()) {
		QString s = QString::fromStdString(it.getDesc()+"  |  "+it.getStatus());
		if (c->getP(it.getProg()) != "")
			s += QString::fromStdString("  |  " + c->getP(it.getProg()));
		ui.listTasks->addItem(new QListWidgetItem(s));
	}
	c->writeToFile();
}
void Programmers::addTask()

{
	
	string desc = ui.Description->text().toStdString();
	c->addTask(desc);
	populateList();
	


}
int Programmers::getSelectedItem() {
	auto v = ui.listTasks->selectedItems();
	if (v.size() == 0)
		return -1;
	return ui.listTasks->row(v[0]);
}
void Programmers::removeTask()
{
		int idx = getSelectedItem();
	if (idx == -1)
		return;
	c->removeT(c->getTasks()[idx]);
	populateList();
}
void Programmers::startTask()
{
	int idx = getSelectedItem();
	if (idx == -1)
		return;
	//c->getTasks()[idx].setStatus("in progress");
	try
	{
		c->startTask(c->getTasks()[idx], p.getId());
		populateList();
	}
	catch (conException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}

}
void Programmers::closeTask()
{
	int idx = getSelectedItem();
	if (idx == -1)
		return;
	c->closeTask(c->getTasks()[idx],p.getId());
	populateList();
}
Programmers::~Programmers()
{

}
