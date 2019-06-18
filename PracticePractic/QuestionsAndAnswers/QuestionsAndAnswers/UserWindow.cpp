#include "UserWindow.h"
#include <qmessagebox.h>
UserWindow::UserWindow(Controller &controller, User user,QWidget *parent)
	: controller(controller),user(user),QWidget(parent)
{
	ui.setupUi(this);
	QWidget::setWindowTitle(user.getName().c_str());
	update();
	controller.registerObs(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(add()));
	connect(ui.listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(changed()));
	connect(ui.answerButton, SIGNAL(clicked()), this, SLOT(answer()));
}

void UserWindow::update()
{
	ui.listWidget->clear();
	for (auto quest : controller.getQuestionsSorted())
	{
		QListWidgetItem *item = new QListWidgetItem{ quest.toString().c_str() };
		ui.listWidget->addItem(item);
	}

}

void UserWindow::add()
{
	int id = stoi(ui.id->text().toStdString());
	string text = ui.text->text().toStdString();
	try {
		controller.addQuestion(id, user, text);
		update();
	}
	catch (Exception& exc)
	{
		QMessageBox* msg = new QMessageBox();
		msg->critical(this,"Error", exc.getMsg().c_str());
	}
}

void UserWindow::changed()
{
	ui.secondList->clear();
	int crtRow = ui.listWidget->currentRow();
	Question q = controller.getQuestionsSorted()[crtRow];
	for (auto answ : controller.getAnswersToQuestion(q)) {
		QListWidgetItem *item = new QListWidgetItem{ answ.toString().c_str() };
		if (answ.getName() == user.getName())
			item->setBackgroundColor(QColor(Qt::GlobalColor::yellow));
		ui.secondList->addItem(item);
	}
}

void UserWindow::answer()
{
	int id = stoi(ui.answerId->text().toStdString());
	int crtRow = ui.listWidget->currentRow();
	Question q = controller.getQuestionsSorted()[crtRow];
	int questId = q.getId();
	string answer = ui.answerText->text().toStdString();
	string name = user.getName();
	try {
		controller.addAnswer(id, questId, answer, name);
		update();
	}
	catch (Exception& exc)
	{
		QMessageBox* msg = new QMessageBox();
		msg->critical(this, "Error", exc.getMsg().c_str());
	}
}