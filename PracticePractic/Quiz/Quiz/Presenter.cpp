#include "Presenter.h"
#include <qlistwidget.h>
#include <qmessagebox.h>
Presenter::Presenter(Controller &c,QWidget *parent)
	: c(c),QWidget(parent)
{
	ui.setupUi(this);
	populate();
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(add()));
}

void Presenter::add()
{
	int id = std::stoi(ui.lineEdit->text().toStdString());
	std::string text = ui.lineEdit_2->text().toStdString(), answer = ui.lineEdit_3->text().toStdString();
	if (!c.add(id, text, answer))
	{
		QMessageBox *msgBox = new QMessageBox();
		msgBox->critical(this,"Error","Operation failed.");
	}
	populate();
}
Presenter::~Presenter()
{

}

void Presenter::populate()
{
	ui.listWidget->clear();
	for (auto q : c.getQuestionsSortedByID()) {
		QListWidgetItem *item = new QListWidgetItem{ q->toString().c_str() };
		ui.listWidget->addItem(item);
	}
}
