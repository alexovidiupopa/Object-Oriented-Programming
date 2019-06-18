#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Quiz.h"

class Quiz : public QMainWindow
{
	Q_OBJECT

public:
	Quiz(QWidget *parent = Q_NULLPTR);

private:
	Ui::QuizClass ui;
};
