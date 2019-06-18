/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QLineEdit *descriptionInput;
    QLineEdit *actInput;
    QPushButton *addButton;
    QPushButton *acceptButton;
    QPushButton *savePlotButton;

    void setupUi(QWidget *guiClass)
    {
        if (guiClass->objectName().isEmpty())
            guiClass->setObjectName(QString::fromUtf8("guiClass"));
        guiClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(guiClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(guiClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        descriptionInput = new QLineEdit(guiClass);
        descriptionInput->setObjectName(QString::fromUtf8("descriptionInput"));

        verticalLayout->addWidget(descriptionInput);

        actInput = new QLineEdit(guiClass);
        actInput->setObjectName(QString::fromUtf8("actInput"));

        verticalLayout->addWidget(actInput);

        addButton = new QPushButton(guiClass);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        acceptButton = new QPushButton(guiClass);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        verticalLayout->addWidget(acceptButton);

        savePlotButton = new QPushButton(guiClass);
        savePlotButton->setObjectName(QString::fromUtf8("savePlotButton"));

        verticalLayout->addWidget(savePlotButton);


        retranslateUi(guiClass);

        QMetaObject::connectSlotsByName(guiClass);
    } // setupUi

    void retranslateUi(QWidget *guiClass)
    {
        guiClass->setWindowTitle(QApplication::translate("guiClass", "gui", nullptr));
        descriptionInput->setPlaceholderText(QApplication::translate("guiClass", "input description", nullptr));
        actInput->setPlaceholderText(QApplication::translate("guiClass", "input act", nullptr));
        addButton->setText(QApplication::translate("guiClass", "add", nullptr));
        acceptButton->setText(QApplication::translate("guiClass", "accept", nullptr));
        savePlotButton->setText(QApplication::translate("guiClass", "save plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiClass: public Ui_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
