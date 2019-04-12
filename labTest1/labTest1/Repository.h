#pragma once
#include "RobotTile.h"
#include <vector>
class Repository {

private: 
	std::vector<Tile> checkedTiles;
	
public:
	
	Tile getCurrentPosition();

	bool tileAlreadyVisited(Tile tileToCheck);

	bool moveRobot(Tile newTile);

	bool invalidTile(Tile tileToCheck);

	std::vector<Tile> getAllTilesScanned();
};