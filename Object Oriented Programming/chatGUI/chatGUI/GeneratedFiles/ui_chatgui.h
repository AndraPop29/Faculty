/********************************************************************************
** Form generated from reading UI file 'chatgui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATGUI_H
#define UI_CHATGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatGUIClass
{
public:
    QWidget *centralWidget;
    QLineEdit *mes;
    QPushButton *sendBut;
    QLabel *label;
    QPushButton *clearBut;
    QListWidget *listMessages;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chatGUIClass)
    {
        if (chatGUIClass->objectName().isEmpty())
            chatGUIClass->setObjectName(QStringLiteral("chatGUIClass"));
        chatGUIClass->resize(617, 896);
        centralWidget = new QWidget(chatGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mes = new QLineEdit(centralWidget);
        mes->setObjectName(QStringLiteral("mes"));
        mes->setGeometry(QRect(80, 570, 381, 31));
        sendBut = new QPushButton(centralWidget);
        sendBut->setObjectName(QStringLiteral("sendBut"));
        sendBut->setGeometry(QRect(470, 570, 121, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 580, 61, 21));
        clearBut = new QPushButton(centralWidget);
        clearBut->setObjectName(QStringLiteral("clearBut"));
        clearBut->setGeometry(QRect(0, 620, 581, 31));
        listMessages = new QListWidget(centralWidget);
        listMessages->setObjectName(QStringLiteral("listMessages"));
        listMessages->setGeometry(QRect(0, 10, 599, 349));
        chatGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chatGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 21));
        chatGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chatGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        chatGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chatGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        chatGUIClass->setStatusBar(statusBar);

        retranslateUi(chatGUIClass);

        QMetaObject::connectSlotsByName(chatGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *chatGUIClass)
    {
        chatGUIClass->setWindowTitle(QApplication::translate("chatGUIClass", "chatGUI", 0));
        sendBut->setText(QApplication::translate("chatGUIClass", "Send", 0));
        label->setText(QApplication::translate("chatGUIClass", "Message:", 0));
        clearBut->setText(QApplication::translate("chatGUIClass", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class chatGUIClass: public Ui_chatGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATGUI_H
