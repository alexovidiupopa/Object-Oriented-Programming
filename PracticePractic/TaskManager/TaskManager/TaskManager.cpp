#include "TaskManager.h"
#include <qmessagebox.h>
TaskManager::TaskManager(Controller* ctrl, Programmer prog, QWidget *parent)
	: ctrl(ctrl),prog(prog),QWidget(parent),Observer()
{	
	ui.setupUi(this); 
	populate();
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(add()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(remove()));
	connect(ui.listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(changed()));
	connect(ui.doneButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(start()));
	ctrl->registerObserver(this);
	QWidget::setWindowTitle(prog.getName().c_str());
	ui.doneButton->setDisabled(true);
}

void TaskManager::populate()
{
	ui.listWidget->clear();
	for (auto tasks : ctrl->getTasksSorted()) {
		QListWidgetItem *item = new QListWidgetItem{ tasks.toString().c_str() };
		ui.listWidget->addItem(item);
	}
	//ui.listWidget->setCurrentRow(0);
}

void TaskManager::update()
{
	ui.listWidget->clear();
	for (auto tasks : ctrl->getTasksSorted()) {
		QListWidgetItem *item = new QListWidgetItem{ tasks.toString().c_str() };
		ui.listWidget->addItem(item);
	}
	//ui.listWidget->setCurrentRow(0);
}

void TaskManager::add()
{
	std::string desc = ui.input->text().toStdString();
	ctrl->add(desc);
	ui.input->clear();
	update();
}

void TaskManager::remove()
{
	std::string desc = ui.input->text().toStdString();
	ctrl->remove(desc);
	ui.input->clear();
	update();
}

void TaskManager::changed()
{
	int row = ui.listWidget->currentRow();
	Task currentTask = ctrl->getTasksSorted()[row];
	if (currentTask.getStatus() == "in progress" && prog.getId() == currentTask.getProgId()) {
		ui.doneButton->setDisabled(false);
	}
	else
	{
		ui.doneButton->setDisabled(true);
	}
}

void TaskManager::close()
{
	int row = ui.listWidget->currentRow();
	Task currentTask = ctrl->getTasksSorted()[row];
	ctrl->close(currentTask);
	update();
}

void TaskManager::start()
{
	int row = ui.listWidget->currentRow();
	Task currentTask = ctrl->getTasksSorted()[row];
	try {
		ctrl->start(currentTask,prog);
		update();
	}
	catch (TaskException &exc) {
		QMessageBox msgBox;
		msgBox.critical(this, "Error", "Operation Failed.");
	}
	
}