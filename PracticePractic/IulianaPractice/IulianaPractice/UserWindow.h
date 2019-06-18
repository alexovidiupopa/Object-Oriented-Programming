#pragma once
#include "Controller.h"
#include <QtWidgets/QMainWindow>
#include "ui_UserWindow.h"

class UserWindow : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	UserWindow(Controller& c, User u,QWidget *parent = Q_NULLPTR);

private:
	Controller& c;
	User u;
	void update();
	Ui::UserWindowClass ui;
private slots:
	void add();
	void checkChange();
	void remove();
	void resolve();
};
