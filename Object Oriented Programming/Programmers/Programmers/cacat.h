#ifndef CACAT_H
#define CACAT_H

#include <QWidget>
#include "ui_cacat.h"

class Cacat : public QWidget
{
	Q_OBJECT

public:
	Cacat(QWidget *parent = 0);
	~Cacat();

private:
	Ui::Cacat ui;
};

#endif // CACAT_H
