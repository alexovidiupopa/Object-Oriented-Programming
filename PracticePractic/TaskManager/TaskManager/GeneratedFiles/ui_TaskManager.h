/********************************************************************************
** Form generated from reading UI file 'TaskManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManagerClass
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *addButton;
    QLineEdit *input;
    QPushButton *deleteButton;
    QPushButton *doneButton;
    QPushButton *startButton;

    void setupUi(QWidget *TaskManagerClass)
    {
        if (TaskManagerClass->objectName().isEmpty())
            TaskManagerClass->setObjectName(QString::fromUtf8("TaskManagerClass"));
        TaskManagerClass->resize(782, 816);
        verticalLayout = new QVBoxLayout(TaskManagerClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(TaskManagerClass);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        addButton = new QPushButton(TaskManagerClass);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        input = new QLineEdit(TaskManagerClass);
        input->setObjectName(QString::fromUtf8("input"));

        verticalLayout->addWidget(input);

        deleteButton = new QPushButton(TaskManagerClass);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        doneButton = new QPushButton(TaskManagerClass);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));

        verticalLayout->addWidget(doneButton);

        startButton = new QPushButton(TaskManagerClass);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout->addWidget(startButton);


        retranslateUi(TaskManagerClass);

        QMetaObject::connectSlotsByName(TaskManagerClass);
    } // setupUi

    void retranslateUi(QWidget *TaskManagerClass)
    {
        TaskManagerClass->setWindowTitle(QApplication::translate("TaskManagerClass", "TaskManager", nullptr));
        addButton->setText(QApplication::translate("TaskManagerClass", "Add", nullptr));
        deleteButton->setText(QApplication::translate("TaskManagerClass", "Delete", nullptr));
        doneButton->setText(QApplication::translate("TaskManagerClass", "Done", nullptr));
        startButton->setText(QApplication::translate("TaskManagerClass", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerClass: public Ui_TaskManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
