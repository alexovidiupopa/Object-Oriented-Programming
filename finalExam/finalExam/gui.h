#pragma once

#include <QtWidgets/QWidget>
#include "ui_gui.h"
#include "Model.h"
class gui : public QWidget
{
	Q_OBJECT

public:
	gui(Model* model,Writer writer, QWidget *parent = Q_NULLPTR);

private:
	Ui::guiClass ui;
	Model *model;
	Writer writer;
	string writerName, writerExpertise;
	void connectButtonsAndHandlers();
private slots: 
	void addHandler();
	void acceptHandler();
	void savePlotHandler();
};
