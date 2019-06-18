/********************************************************************************
** Form generated from reading UI file 'Presenter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTER_H
#define UI_PRESENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Presenter
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Presenter)
    {
        if (Presenter->objectName().isEmpty())
            Presenter->setObjectName(QString::fromUtf8("Presenter"));
        Presenter->resize(849, 805);
        verticalLayout = new QVBoxLayout(Presenter);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Presenter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        lineEdit = new QLineEdit(Presenter);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(Presenter);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(Presenter);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        pushButton = new QPushButton(Presenter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Presenter);

        QMetaObject::connectSlotsByName(Presenter);
    } // setupUi

    void retranslateUi(QWidget *Presenter)
    {
        Presenter->setWindowTitle(QApplication::translate("Presenter", "Presenter", nullptr));
        pushButton->setText(QApplication::translate("Presenter", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Presenter: public Ui_Presenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTER_H
