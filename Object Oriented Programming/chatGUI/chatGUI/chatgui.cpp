#include "chatgui.h"
#include <qdebug.h>
#include <qrect.h>
#include "qmessagebox.h"
#include <qpainter.h>

chatGUI::chatGUI(Controller *_c, User _u, QWidget *parent)
	:c(_c), u(_u), QMainWindow(parent)
{
	ui.setupUi(this);
	QWidget::setWindowTitle(QString::fromStdString(u.getName()));
	loadList();
	connectSignalsAndSlots();
	drawTable();
}
void chatGUI::connectSignalsAndSlots() {
	QObject::connect(ui.sendBut, SIGNAL(clicked()), this, SLOT(sendMess()));
	QObject::connect(ui.clearBut, SIGNAL(clicked()), this, SLOT(clearMess()));
}
void chatGUI::loadList()
{
	ui.listMessages->clear();
	for (auto m : c->getMessages())
	{
		QString s = QString::fromStdString(m.getText());
			if (c->getName(m.getUser())!="")
				s += QString::fromStdString(" - " + c->getName(m.getUser()));
		ui.listMessages->addItem(new QListWidgetItem(s));
	}
}

void chatGUI::sendMess() {
	try
	{
		string m = ui.mes->text().toStdString();
		c->addMessage(m, u.getId());
		loadList();
	}
	catch (conException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMes()));
	}
	drawTable();
}
void chatGUI::clearMess()
{
	c->clearMessages();
	loadList();
}

void chatGUI::drawTable()
{
	QPainter painter{ this };
	painter.eraseRect(0, 0, 600, 400);

	// draw a rectangle
	// first change the pen
	QPen pen1{ Qt::green, 3, Qt::DashDotDotLine, Qt::RoundCap };
	painter.setPen(pen1);
	painter.setBrush(Qt::NoBrush);
	int mes = 0;
	/*for (auto it : c->getMessages())
		if (it.getUser() == 2)
			mes = mes + 10;
	QRect rectangle(10, 500, 100, -mes);
	QRect re();

	painter.drawRect(rectangle);
	for (auto it : c->getMessages())
		if (it.getUser() == 1)
			mes = mes + 10;
	QRect rec(150, 500, 100, -mes);
	QRect re();
	painter.drawRect(rec);*/
	//int d = 0;
	vector<User> users = c->getUsers();
	vector<Message> messages = c->getMessages();
	for (int i = 0; i < users.size(); i++)
	{
		
		mes = 0;
		for (int j = 0; j < messages.size(); j++)
			if (users[i].getId() == messages[j].getUser())
				mes++;
		QRect rectangle(100*i, 500, 100, -(mes*10));
		painter.drawRect(rectangle);
		QLabel* qlbl = new QLabel(QString::fromStdString(users[i].getName()), this);
		qlbl->setGeometry(100 * i, 510, 100, 10);
	}
	 
	/*for (int i = 0; i < c->getMessages().size();i++)
	{
		if (c->getMessages()[i].getUser() == u.getId())
		{
			mes = mes + 10;
			
		}
		QRect rectangle(getDist(), 500, 100, mes);
		QRect re();
		painter.drawRect(rectangle);
	}
*/
	
}


chatGUI::~chatGUI()
{

}
