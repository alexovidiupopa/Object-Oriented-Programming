#include "SearchWindow.h"

SearchWindow::SearchWindow(Controller &controller,QWidget *parent)
	: controller(controller),QWidget(parent)
{
	ui.setupUi(this);
	controller.registerObs(this);
	connect(ui.lineEdit, SIGNAL(textChanged(QString)), this, SLOT(update()));
}

SearchWindow::~SearchWindow()
{
}

void SearchWindow::update()
{
	ui.listWidget->clear();
	string text = ui.lineEdit->text().toStdString();
	Question q = controller.getBestMatchingQuestion(text);
	vector<Answer> topThreeAnswers = controller.topThreeAnswers(q);
	QListWidgetItem *item = new QListWidgetItem{ q.toString().c_str() };
	ui.listWidget->addItem(item);
	for (auto ans : topThreeAnswers) {
		QListWidgetItem *item2 = new QListWidgetItem{ ans.toString().c_str() };
		ui.listWidget->addItem(item2);
	}
}
