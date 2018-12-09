/********************************************************************************
** Form generated from reading UI file 'eurovision.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EUROVISION_H
#define UI_EUROVISION_H

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

class Ui_eurovisionClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *eurovisionClass)
    {
        if (eurovisionClass->objectName().isEmpty())
            eurovisionClass->setObjectName(QStringLiteral("eurovisionClass"));
        eurovisionClass->resize(600, 400);
        menuBar = new QMenuBar(eurovisionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        eurovisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(eurovisionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        eurovisionClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(eurovisionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        eurovisionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(eurovisionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        eurovisionClass->setStatusBar(statusBar);

        retranslateUi(eurovisionClass);

        QMetaObject::connectSlotsByName(eurovisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *eurovisionClass)
    {
        eurovisionClass->setWindowTitle(QApplication::translate("eurovisionClass", "eurovision", 0));
    } // retranslateUi

};

namespace Ui {
    class eurovisionClass: public Ui_eurovisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EUROVISION_H
