#include "gui.h"

gui::gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	populate();
	connect(ui.lineEdit, SIGNAL(textChanged(QString)), this, SLOT(refreshSearch()));
	connect(ui.bestMatchButton, SIGNAL(clicked()), this, SLOT(bestMatching()));
}

void gui::populate()
{
	ui.listWidget->clear();
	for (auto documents : controller.getDocuments()) {
		QListWidgetItem *listItem = new QListWidgetItem{documents.toStringNoContent().c_str()};
		ui.listWidget->addItem(listItem);
	}
}

void gui::refreshSearch()
{
	
	std::string currentText = ui.lineEdit->text().toStdString();
	ui.listWidget->clear();
	for (auto documents : controller.getPartialMatching(currentText)) {
		QListWidgetItem *listItem = new QListWidgetItem{ documents.toStringNoContent().c_str() };
		ui.listWidget->addItem(listItem);
	}
}

void gui::bestMatching()
{
	ui.label->clear();
	std::string currentText = ui.lineEdit->text().toStdString();
	ui.label->setText(controller.getBestMatch(currentText).toStringContent().c_str());
}