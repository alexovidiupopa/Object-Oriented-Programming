#pragma once

#include <QWidget>
#include "ui_ParticipantWindow.h"
#include "Controller.h"
#include "Observer.h"
class ParticipantWindow : public QWidget,public Observer
{
	Q_OBJECT

public:
	ParticipantWindow(Controller &c,std::string name,QWidget *parent = Q_NULLPTR);
	~ParticipantWindow();

private:
	Ui::ParticipantWindow ui;
	Controller &c;
	std::string name;
	void populate();
	int score;
	void update()override;
private slots:
	void answer();
	void changeColor();
};
