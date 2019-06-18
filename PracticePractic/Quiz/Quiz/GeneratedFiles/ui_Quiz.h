/********************************************************************************
** Form generated from reading UI file 'Quiz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZ_H
#define UI_QUIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuizClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuizClass)
    {
        if (QuizClass->objectName().isEmpty())
            QuizClass->setObjectName(QString::fromUtf8("QuizClass"));
        QuizClass->resize(600, 400);
        menuBar = new QMenuBar(QuizClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QuizClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuizClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QuizClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QuizClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QuizClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QuizClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QuizClass->setStatusBar(statusBar);

        retranslateUi(QuizClass);

        QMetaObject::connectSlotsByName(QuizClass);
    } // setupUi

    void retranslateUi(QMainWindow *QuizClass)
    {
        QuizClass->setWindowTitle(QApplication::translate("QuizClass", "Quiz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuizClass: public Ui_QuizClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZ_H
