/********************************************************************************
** Form generated from reading UI file 'programmers.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMERS_H
#define UI_PROGRAMMERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammersClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QListWidget *listTasks;
    QLabel *label;
    QLineEdit *Description;
    QPushButton *AddBut;
    QPushButton *removeBut;
    QPushButton *startBut;
    QPushButton *closeBut;

    void setupUi(QWidget *ProgrammersClass)
    {
        if (ProgrammersClass->objectName().isEmpty())
            ProgrammersClass->setObjectName(QStringLiteral("ProgrammersClass"));
        ProgrammersClass->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(ProgrammersClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        listTasks = new QListWidget(ProgrammersClass);
        listTasks->setObjectName(QStringLiteral("listTasks"));

        verticalLayout->addWidget(listTasks);

        label = new QLabel(ProgrammersClass);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        Description = new QLineEdit(ProgrammersClass);
        Description->setObjectName(QStringLiteral("Description"));

        verticalLayout->addWidget(Description);

        AddBut = new QPushButton(ProgrammersClass);
        AddBut->setObjectName(QStringLiteral("AddBut"));

        verticalLayout->addWidget(AddBut);

        removeBut = new QPushButton(ProgrammersClass);
        removeBut->setObjectName(QStringLiteral("removeBut"));

        verticalLayout->addWidget(removeBut);

        startBut = new QPushButton(ProgrammersClass);
        startBut->setObjectName(QStringLiteral("startBut"));

        verticalLayout->addWidget(startBut);


        verticalLayout_2->addLayout(verticalLayout);

        closeBut = new QPushButton(ProgrammersClass);
        closeBut->setObjectName(QStringLiteral("closeBut"));

        verticalLayout_2->addWidget(closeBut);


        retranslateUi(ProgrammersClass);

        QMetaObject::connectSlotsByName(ProgrammersClass);
    } // setupUi

    void retranslateUi(QWidget *ProgrammersClass)
    {
        ProgrammersClass->setWindowTitle(QApplication::translate("ProgrammersClass", "Programmers", 0));
        label->setText(QApplication::translate("ProgrammersClass", "Task description:", 0));
        AddBut->setText(QApplication::translate("ProgrammersClass", "Add", 0));
        removeBut->setText(QApplication::translate("ProgrammersClass", "Remove", 0));
        startBut->setText(QApplication::translate("ProgrammersClass", "Start", 0));
        closeBut->setText(QApplication::translate("ProgrammersClass", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgrammersClass: public Ui_ProgrammersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERS_H
