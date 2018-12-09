/********************************************************************************
** Form generated from reading UI file 'adminagui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINAGUI_H
#define UI_ADMINAGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminaGUI
{
public:
    QListWidget *listStudents;
    QLineEdit *nameEdit;
    QLineEdit *groupEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *addBut;
    QPushButton *removeBut;
    QLineEdit *idEdit;
    QLabel *label_3;

    void setupUi(QWidget *adminaGUI)
    {
        if (adminaGUI->objectName().isEmpty())
            adminaGUI->setObjectName(QStringLiteral("adminaGUI"));
        adminaGUI->resize(400, 417);
        listStudents = new QListWidget(adminaGUI);
        listStudents->setObjectName(QStringLiteral("listStudents"));
        listStudents->setGeometry(QRect(15, 11, 371, 221));
        nameEdit = new QLineEdit(adminaGUI);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(100, 290, 291, 31));
        groupEdit = new QLineEdit(adminaGUI);
        groupEdit->setObjectName(QStringLiteral("groupEdit"));
        groupEdit->setGeometry(QRect(100, 330, 291, 31));
        label = new QLabel(adminaGUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 300, 47, 13));
        label_2 = new QLabel(adminaGUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 340, 47, 13));
        addBut = new QPushButton(adminaGUI);
        addBut->setObjectName(QStringLiteral("addBut"));
        addBut->setGeometry(QRect(20, 380, 141, 21));
        removeBut = new QPushButton(adminaGUI);
        removeBut->setObjectName(QStringLiteral("removeBut"));
        removeBut->setGeometry(QRect(230, 380, 141, 21));
        idEdit = new QLineEdit(adminaGUI);
        idEdit->setObjectName(QStringLiteral("idEdit"));
        idEdit->setGeometry(QRect(100, 250, 291, 31));
        label_3 = new QLabel(adminaGUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 260, 47, 13));

        retranslateUi(adminaGUI);

        QMetaObject::connectSlotsByName(adminaGUI);
    } // setupUi

    void retranslateUi(QWidget *adminaGUI)
    {
        adminaGUI->setWindowTitle(QApplication::translate("adminaGUI", "adminaGUI", 0));
        label->setText(QApplication::translate("adminaGUI", "Name:", 0));
        label_2->setText(QApplication::translate("adminaGUI", "Group:", 0));
        addBut->setText(QApplication::translate("adminaGUI", "Add", 0));
        removeBut->setText(QApplication::translate("adminaGUI", "Remove", 0));
        label_3->setText(QApplication::translate("adminaGUI", "Id:", 0));
    } // retranslateUi

};

namespace Ui {
    class adminaGUI: public Ui_adminaGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINAGUI_H
