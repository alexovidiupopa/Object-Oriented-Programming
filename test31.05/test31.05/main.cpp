#include "gui.h"
#include <QtWidgets/QApplication>
#include "Testing.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Testing tests{};
	//tests.runTests();
	gui w;
	w.show();
	return a.exec();
}
