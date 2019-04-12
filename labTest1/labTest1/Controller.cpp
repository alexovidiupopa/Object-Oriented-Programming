#include "Controller.h"
#include <cstring>
Controller::Controller(Repository*repository)
{
	this->repository = repository;
}

Controller::~Controller()
{
}

bool Controller::moveRobot(char direction[])
{
	/*
	in:a string representing the direction inputted by the user
	out: true/false, depending on whether the robot was moved
	pre- direction needs to be { "up","down","right","left"} , or it will break
	the function makes the calculations regarding the future robot coordinates based on the direction as follows: 
		up = it needs to increment the y coordinate
		down =it needs to decrement the y coordinate 
		right = it needs to increment the x coordinate
		left = it needs to decrement the x coordinate*/
	Tile lastTile = this->repository->getCurrentPosition();
	if (strcmp(direction, "up") == 0)
		lastTile.setYCoordinate(lastTile.getYCoordinate() + 1);
	else if (strcmp(direction, "down") == 0)
		lastTile.setYCoordinate(lastTile.getYCoordinate() - 1);
	else if (strcmp(direction, "right") == 0)
		lastTile.setXCoordinate(lastTile.getXCoordinate() + 1);
	else if(strcmp(direction,"left")==0)
		lastTile.setXCoordinate(lastTile.getXCoordinate() -1);
	return this->repository->moveRobot(lastTile);
}

float Controller::percentageOfScannedTiles()
{
	/*
	  int- 
	  out - a float value representing the percentage of the scanned tiles
	  pre: - 
	  post: - 
	  The value is computed using the classical rule of third from mathematics.
	  */
	int totalAreaToCover = 121;
	int coveredSoFar = this->repository->getAllTilesScanned().size();
	return float(float(100 * coveredSoFar )/ float(totalAreaToCover));
}

std::vector<Tile> Controller::listTiles()
{
	return this->repository->getAllTilesScanned();
}
