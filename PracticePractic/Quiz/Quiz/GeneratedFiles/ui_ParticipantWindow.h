/********************************************************************************
** Form generated from reading UI file 'ParticipantWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTICIPANTWINDOW_H
#define UI_PARTICIPANTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParticipantWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *ParticipantWindow)
    {
        if (ParticipantWindow->objectName().isEmpty())
            ParticipantWindow->setObjectName(QString::fromUtf8("ParticipantWindow"));
        ParticipantWindow->resize(696, 615);
        verticalLayout = new QVBoxLayout(ParticipantWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ParticipantWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(ParticipantWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        lineEdit = new QLineEdit(ParticipantWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label = new QLabel(ParticipantWindow);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        retranslateUi(ParticipantWindow);

        QMetaObject::connectSlotsByName(ParticipantWindow);
    } // setupUi

    void retranslateUi(QWidget *ParticipantWindow)
    {
        ParticipantWindow->setWindowTitle(QApplication::translate("ParticipantWindow", "ParticipantWindow", nullptr));
        pushButton->setText(QApplication::translate("ParticipantWindow", "Answer", nullptr));
        label->setText(QApplication::translate("ParticipantWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParticipantWindow: public Ui_ParticipantWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTICIPANTWINDOW_H
