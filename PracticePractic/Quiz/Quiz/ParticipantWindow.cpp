#include "ParticipantWindow.h"
#include "qlistwidget.h"
ParticipantWindow::ParticipantWindow(Controller &c,std::string name,QWidget *parent)
	: c(c), name(name),QWidget(parent), Observer()
{
	
	ui.setupUi(this);
	QWidget::setWindowTitle(name.c_str());
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(answer()));
	QObject::connect(ui.listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(changeColor()));
	c.registerObserver(this);
	ui.label->setText("0");
	populate();
}

void ParticipantWindow::answer()
{
	int row = ui.listWidget->currentRow();
	std::string answer = ui.lineEdit->text().toStdString();
	if (c.answer(answer, row,name)) {
		ui.listWidget->item(row)->setBackgroundColor(QColor::QColor(Qt::GlobalColor::green));
		ui.label->clear();
		ui.label->setText(std::to_string(c.getCurrentScore(name)).c_str());
	}
	
}

void ParticipantWindow::changeColor()
{
	int row = ui.listWidget->currentRow();
	if (ui.listWidget->item(row)->backgroundColor() == QColor::QColor(Qt::GlobalColor::green))
	{
		ui.pushButton->setDisabled(true);
	}
	else
	{
		ui.pushButton->setDisabled(false);
	}
}
ParticipantWindow::~ParticipantWindow()
{
	delete &c;
}

void ParticipantWindow::populate()
{
	ui.listWidget->clear();
	for (auto q : c.getQuestionsSortedByScore()) {
		QListWidgetItem *item = new QListWidgetItem{ q->toString().c_str() };
		ui.listWidget->addItem(item);
	}
	ui.listWidget->setCurrentRow(0);
}

void ParticipantWindow::update()
{
	ui.listWidget->clear();
	for (auto q : c.getQuestionsSortedByScore()) {
		QListWidgetItem *item = new QListWidgetItem{ q->toString().c_str() };
		ui.listWidget->addItem(item);
	}
	ui.listWidget->setCurrentRow(0);
}
