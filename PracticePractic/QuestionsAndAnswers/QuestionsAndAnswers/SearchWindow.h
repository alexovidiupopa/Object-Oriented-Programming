#pragma once

#include <QWidget>
#include "ui_SearchWindow.h"
#include "Controller.h"
class SearchWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	SearchWindow(Controller &controller,QWidget *parent = Q_NULLPTR);
	~SearchWindow();

private:
	Controller &controller;
	
	Ui::SearchWindow ui;
private slots:
	void update()override;
};
