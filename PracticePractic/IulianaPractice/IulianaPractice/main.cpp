#include "UserWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Controller ctrl{ repo };

	vector<UserWindow*> wnds;
	for (auto us : repo.getUsers()) {
		wnds.push_back(new UserWindow{ ctrl,us });
	}
	for (auto wnd : wnds)
		wnd->show();
	return a.exec();
}
