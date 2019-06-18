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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindowClass
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLineEdit *id;
    QLineEdit *text;
    QPushButton *pushButton;
    QListWidget *secondList;
    QLineEdit *answerId;
    QLineEdit *answerText;
    QPushButton *answerButton;

    void setupUi(QWidget *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName(QString::fromUtf8("UserWindowClass"));
        UserWindowClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(UserWindowClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(UserWindowClass);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        id = new QLineEdit(UserWindowClass);
        id->setObjectName(QString::fromUtf8("id"));

        verticalLayout->addWidget(id);

        text = new QLineEdit(UserWindowClass);
        text->setObjectName(QString::fromUtf8("text"));

        verticalLayout->addWidget(text);

        pushButton = new QPushButton(UserWindowClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        secondList = new QListWidget(UserWindowClass);
        secondList->setObjectName(QString::fromUtf8("secondList"));

        verticalLayout->addWidget(secondList);

        answerId = new QLineEdit(UserWindowClass);
        answerId->setObjectName(QString::fromUtf8("answerId"));

        verticalLayout->addWidget(answerId);

        answerText = new QLineEdit(UserWindowClass);
        answerText->setObjectName(QString::fromUtf8("answerText"));

        verticalLayout->addWidget(answerText);

        answerButton = new QPushButton(UserWindowClass);
        answerButton->setObjectName(QString::fromUtf8("answerButton"));

        verticalLayout->addWidget(answerButton);


        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QWidget *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QApplication::translate("UserWindowClass", "UserWindow", nullptr));
        pushButton->setText(QApplication::translate("UserWindowClass", "add", nullptr));
        answerButton->setText(QApplication::translate("UserWindowClass", "Answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
