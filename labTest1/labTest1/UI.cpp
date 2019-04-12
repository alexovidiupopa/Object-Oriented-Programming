#include "UI.h"
#include <iomanip>
void UI::listAllRobots()
{
	std::vector<Tile> robots = this->controller.listTiles();
	for (int i = 0; i < robots.size(); i++) {
		std::cout << robots[i].getXCoordinate() << " " << robots[i].getYCoordinate() << std::endl;
	}
	std::cout << "Area covered:";
	double percantageOfScannedTiles = this->controller.percentageOfScannedTiles();
	std::cout<<std::setprecision(3) << percantageOfScannedTiles << "%";
}

void UI::moveRobot()
{
	char dir[11];
	std::cin >> dir;
	if (!this->controller.moveRobot(dir))
		std::cout << "Couldnt move robot";
	else {
		std::vector<Tile> robots = this->controller.listTiles();
		std::cout << robots[robots.size() - 1].getXCoordinate() << " " << robots[robots.size() - 1].getYCoordinate();
	}
}

UI::~UI()
{
}

void UI::run()
{
	while (true) {
		std::cout << "\n1.Add robot\n2.List all positions\n";
		int cmd;
		std::cin >> cmd;
		if (cmd == 1) {
			this->moveRobot();
		}
		else if (cmd == 2) {
			this->listAllRobots();
		}
		else continue;
	}
}
