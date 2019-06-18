/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *addBtn;
    QLineEdit *issueEdit;
    QPushButton *removeBtn;
    QPushButton *resolveBtn;

    void setupUi(QMainWindow *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName(QString::fromUtf8("UserWindowClass"));
        UserWindowClass->resize(790, 633);
        centralWidget = new QWidget(UserWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        verticalLayout->addWidget(addBtn);

        issueEdit = new QLineEdit(centralWidget);
        issueEdit->setObjectName(QString::fromUtf8("issueEdit"));

        verticalLayout->addWidget(issueEdit);

        removeBtn = new QPushButton(centralWidget);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));

        verticalLayout->addWidget(removeBtn);

        resolveBtn = new QPushButton(centralWidget);
        resolveBtn->setObjectName(QString::fromUtf8("resolveBtn"));

        verticalLayout->addWidget(resolveBtn);

        UserWindowClass->setCentralWidget(centralWidget);

        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QApplication::translate("UserWindowClass", "UserWindow", nullptr));
        addBtn->setText(QApplication::translate("UserWindowClass", "add", nullptr));
        removeBtn->setText(QApplication::translate("UserWindowClass", "remove", nullptr));
        resolveBtn->setText(QApplication::translate("UserWindowClass", "resolve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
