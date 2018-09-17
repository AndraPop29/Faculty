/********************************************************************************
** Form generated from reading UI file 'handbal.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDBAL_H
#define UI_HANDBAL_H

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

class Ui_handbalClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *handbalClass)
    {
        if (handbalClass->objectName().isEmpty())
            handbalClass->setObjectName(QStringLiteral("handbalClass"));
        handbalClass->resize(600, 400);
        menuBar = new QMenuBar(handbalClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        handbalClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(handbalClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        handbalClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(handbalClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        handbalClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(handbalClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        handbalClass->setStatusBar(statusBar);

        retranslateUi(handbalClass);

        QMetaObject::connectSlotsByName(handbalClass);
    } // setupUi

    void retranslateUi(QMainWindow *handbalClass)
    {
        handbalClass->setWindowTitle(QApplication::translate("handbalClass", "handbal", 0));
    } // retranslateUi

};

namespace Ui {
    class handbalClass: public Ui_handbalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDBAL_H
