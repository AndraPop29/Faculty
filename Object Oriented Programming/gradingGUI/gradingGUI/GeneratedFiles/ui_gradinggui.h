/********************************************************************************
** Form generated from reading UI file 'gradinggui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADINGGUI_H
#define UI_GRADINGGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gradingGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listStudents;
    QLineEdit *gradeEdit;
    QPushButton *gradeBut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *gradingGUIClass)
    {
        if (gradingGUIClass->objectName().isEmpty())
            gradingGUIClass->setObjectName(QStringLiteral("gradingGUIClass"));
        gradingGUIClass->resize(605, 443);
        centralWidget = new QWidget(gradingGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 601, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listStudents = new QListWidget(verticalLayoutWidget);
        listStudents->setObjectName(QStringLiteral("listStudents"));

        verticalLayout->addWidget(listStudents);

        gradeEdit = new QLineEdit(centralWidget);
        gradeEdit->setObjectName(QStringLiteral("gradeEdit"));
        gradeEdit->setGeometry(QRect(20, 360, 371, 31));
        gradeBut = new QPushButton(centralWidget);
        gradeBut->setObjectName(QStringLiteral("gradeBut"));
        gradeBut->setGeometry(QRect(440, 360, 121, 31));
        gradingGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(gradingGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 21));
        gradingGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(gradingGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        gradingGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(gradingGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        gradingGUIClass->setStatusBar(statusBar);

        retranslateUi(gradingGUIClass);

        QMetaObject::connectSlotsByName(gradingGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *gradingGUIClass)
    {
        gradingGUIClass->setWindowTitle(QApplication::translate("gradingGUIClass", "gradingGUI", 0));
        gradeBut->setText(QApplication::translate("gradingGUIClass", "Grade", 0));
    } // retranslateUi

};

namespace Ui {
    class gradingGUIClass: public Ui_gradingGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADINGGUI_H
