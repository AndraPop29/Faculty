/********************************************************************************
** Form generated from reading UI file 'handbal2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDBAL2_H
#define UI_HANDBAL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Handbal2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Handbal2Class)
    {
        if (Handbal2Class->objectName().isEmpty())
            Handbal2Class->setObjectName(QStringLiteral("Handbal2Class"));
        Handbal2Class->resize(600, 400);
        menuBar = new QMenuBar(Handbal2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Handbal2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Handbal2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Handbal2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Handbal2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Handbal2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Handbal2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Handbal2Class->setStatusBar(statusBar);

        retranslateUi(Handbal2Class);

        QMetaObject::connectSlotsByName(Handbal2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Handbal2Class)
    {
        Handbal2Class->setWindowTitle(QApplication::translate("Handbal2Class", "Handbal2", 0));
    } // retranslateUi

};

namespace Ui {
    class Handbal2Class: public Ui_Handbal2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDBAL2_H
