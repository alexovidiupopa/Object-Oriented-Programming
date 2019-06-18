#include "UserWindow.h"
#include <qmessagebox.h>
UserWindow::UserWindow(Controller& c, User u, QWidget *parent)
	: c(c),u(u),QMainWindow(parent)
{
	ui.setupUi(this);
	c.registerObs(this);
	update();
	QWidget::setWindowTitle((u.getName() + "-" + u.getType()).c_str());
	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(add()));
	if (u.getType() == "programmer")
		ui.addBtn->setDisabled(true);
	else
		ui.resolveBtn->setDisabled(true);
	connect(ui.listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(checkChange()));
	connect(ui.removeBtn, SIGNAL(clicked()), this, SLOT(remove()));
	connect(ui.resolveBtn, SIGNAL(clicked()), this, SLOT(resolve()));
}

void UserWindow::update()
{
	ui.listWidget->clear();
	for (auto iss : c.getIssuesSorted())
	{
		QListWidgetItem *item = new QListWidgetItem{ iss.toString().c_str() };
		ui.listWidget->addItem(item);
	}
}

void UserWindow::add()
{
	string description = ui.issueEdit->text().toStdString();
	try {
		c.addIssue(description, u.getName());
	}
	catch (Exception &e) {
		QMessageBox msgBox;
		msgBox.critical(this, "Error", e.getMsg().c_str());
	}
}

void UserWindow::checkChange()
{
	Issuee crtIssue = c.getIssuesSorted()[ui.listWidget->currentRow()];
	if (crtIssue.getStatus() != "closed")
	{
		ui.removeBtn->setDisabled(true);
	}
	else
	{
		ui.removeBtn->setDisabled(false);
	}
	if(u.getType()=="programmer")
		if (crtIssue.getStatus() != "closed")
		{
			ui.resolveBtn->setDisabled(false);
		}
		else
		{
			ui.resolveBtn->setDisabled(true);
		}
}

void UserWindow::remove()
{
	Issuee crtIssue = c.getIssuesSorted()[ui.listWidget->currentRow()];
	c.removeIssue(crtIssue);
}

void UserWindow::resolve()
{
	Issuee crtIssue = c.getIssuesSorted()[ui.listWidget->currentRow()];
	c.solveIssue(crtIssue,u.getName());
}