#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include "SearchWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Controller ctrl{ repo };
	vector<UserWindow*> wnds;
	for (auto users : repo.getUsers())
		wnds.push_back(new UserWindow{ ctrl,users });
	for (auto wnd : wnds)
		wnd->show();
	SearchWindow src{ ctrl };
	src.show();
	return a.exec();
}
