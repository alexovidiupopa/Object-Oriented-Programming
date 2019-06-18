#pragma once
#include <QtWidgets/QApplication>
#include "Presenter.h"
#include "ParticipantWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r{};
	Controller c{ &r };
	Presenter pres(c);
	pres.show();

	std::vector<ParticipantWindow*> windows;
	for (auto p : r.getP()) {
		ParticipantWindow *pwnd = new ParticipantWindow{ c,p->getName() };
		windows.push_back(pwnd);
	}
	for (int i = 0; i < windows.size(); i++) {
		windows[i]->show();
	}
	return a.exec();
}
