#pragma once
#include "Repository.h"

class Controller {
private:
	Repository* repository;

public:

	Controller(Repository* repository);
	~Controller();

	bool moveRobot(char direction[]);

	float percentageOfScannedTiles();
	std::vector<Tile> listTiles();
};