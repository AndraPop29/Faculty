#ifndef HANDBAL2_H
#define HANDBAL2_H

#include <QtWidgets/QMainWindow>
#include "ui_handbal2.h"

class Handbal2 : public QMainWindow
{
	Q_OBJECT

public:
	Handbal2(QWidget *parent = 0);
	~Handbal2();

private:
	Ui::Handbal2Class ui;
};

#endif // HANDBAL2_H
