#pragma once

#include <QtWidgets/QWidget>
#include "ui_TaskManager.h"
#include "Controller.h"
class TaskManager : public QWidget, public Observer
{
	Q_OBJECT

public:
	TaskManager(Controller* ctrl,Programmer prog, QWidget *parent = Q_NULLPTR);

private:
	Controller *ctrl;
	Programmer prog;
	void populate();
	Ui::TaskManagerClass ui;
	void update() override;
private slots:
	void add();
	void remove();
	void changed();
	void close();
	void start();
};
