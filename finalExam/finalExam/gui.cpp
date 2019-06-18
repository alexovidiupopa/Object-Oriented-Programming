#include "gui.h"
#include <qmessagebox.h>
gui::gui(Model* model,Writer writer,QWidget *parent)
	: model(model),QWidget(parent)
{
	ui.setupUi(this);
	writerName = writer.getName();
	writerExpertise = writer.getExpertise();
	//QWidget::setWindowTitle(writer.getName().c_str());
	ui.tableView->setModel(model);
	connectButtonsAndHandlers();
	/*if (writerExpertise != "senior")
		ui.acceptButton->setDisabled(true);
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addHandler()));
	connect(ui.acceptButton, SIGNAL(clicked()), this, SLOT(acceptHandler()));
	connect(ui.savePlotButton, SIGNAL(clicked()), this, SLOT(savePlotHandler()));*/
}

void gui::addHandler()
{
	string description = ui.descriptionInput->text().toStdString();
	string act = ui.actInput->text().toStdString();
	try {
		model->addIdea(description, writerName, act);
	}
	catch (exception &except) {
		QMessageBox messageBox;
		messageBox.critical(this, "Error", except.what());
	}
}

void gui::connectButtonsAndHandlers()
{
	QWidget::setWindowTitle(writerName.c_str());
	if (writerExpertise != "senior")
		ui.acceptButton->setDisabled(true);
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addHandler()));
	connect(ui.acceptButton, SIGNAL(clicked()), this, SLOT(acceptHandler()));
	connect(ui.savePlotButton, SIGNAL(clicked()), this, SLOT(savePlotHandler()));
}

void gui::acceptHandler()
{
	QModelIndex currentLine = ui.tableView->currentIndex();
	model->acceptIdea(currentLine);
}

void gui::savePlotHandler()
{
	model->savePlot();
}