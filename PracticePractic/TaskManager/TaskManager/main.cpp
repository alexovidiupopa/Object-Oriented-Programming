#include "TaskManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Controller ctrl{ &repo };
	std::vector<TaskManager*> windows;
	for (auto progs : repo.getProgs())
	{
		windows.push_back(new TaskManager{ &ctrl,progs });
	}
	for (auto w : windows)
	{
		w->show();
	}
	return a.exec();
}
