#include "gui.h"
#include <QtWidgets/QApplication>
#include "Model.h"
#include "Testing.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Testing tests{};
	Repository repository{true};
	Controller controller{ repository };
	//QAbstractItemModel model = nw
	Model model{ controller };
	vector<gui*> windows;
	for (auto writer : repository.getWriters())
		windows.push_back(new gui{ &model,writer });
	for (auto window : windows)
		window->show();
	return a.exec();
}
