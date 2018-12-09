#include <QtWidgets/QMainWindow>
#include "ui_chatgui.h"
#include "Controller.h"
#include "User.h"
#include "Observer.h"
#include <QtGui>
#include <QtCore>

class chatGUI : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	chatGUI(Controller *_c, User _u, QWidget *parent=0);
	~chatGUI();
	void connectSignalsAndSlots();
	void update()
	{
		loadList();
		drawTable();
		this->repaint();
	}
	void drawTable();


public slots:
	void sendMess();
	void clearMess();
private:
	Ui::chatGUIClass ui;
	Controller* c;
	User u;
	
	void loadList();
protected:
	void paintEvent(QPaintEvent *q) {
		drawTable();
	}

};
