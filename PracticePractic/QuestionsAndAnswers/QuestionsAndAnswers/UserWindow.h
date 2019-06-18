#pragma once

#include <QtWidgets/QWidget>
#include "ui_UserWindow.h"
#include "Controller.h"
class UserWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	UserWindow(Controller &controller, User user,QWidget *parent = Q_NULLPTR);

private:
	Controller &controller;
	User user;
	Ui::UserWindowClass ui;
	void update() override;
private slots: 
	void add();
	void changed();
	void answer();
};
