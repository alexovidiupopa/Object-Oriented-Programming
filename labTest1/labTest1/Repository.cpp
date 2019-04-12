#include "Repository.h"

Tile Repository::getCurrentPosition()
{
	/*in-
	  out- an object of type Tile representing the current position of the robot , i.e. the last element of the repository vector*/
	return this->checkedTiles[this->checkedTiles.size()-1];
}

bool Repository::tileAlreadyVisited(Tile tileToCheck)
{
	/*in - tileToCheck - an object of type Tile
	  out - true if the tile has been already visited, false otherwise
	  the function just iterates through all the tiles visited so far, and if it finds one it has already visited, it returns true*/
	std::vector<Tile> allTiles = this->checkedTiles;
	int sizeOfRepository = allTiles.size();
	for (int i = 0; i < sizeOfRepository; i++) {
		if (tileToCheck.getXCoordinate() == allTiles[i].getXCoordinate() && tileToCheck.getYCoordinate() == allTiles[i].getYCoordinate())
			return true;
	}
	return false;
}

bool Repository::moveRobot(Tile newTile)
{
	/*in- newTile - an object of type Tile
	out - true if the robot was moved, false otherwise
	the function checks whether the robot can be moved based on the functions specified above
	if it can be moved, it is added to the vector.*/
	
	if (this->checkedTiles.size() > 0) {
		if (this->invalidTile(newTile)==false)
			return false;
		if (this->tileAlreadyVisited(newTile))
			return false;
	}
	this->checkedTiles.push_back(newTile);
	return true;
}

bool Repository::invalidTile(Tile tileToCheck)
{
	/*in- tileToCheck - an object of type Tile
	  out- true if the coordinates are ok, false otherwise 
	  just a simple if logical statement to check the requirement. 
	  a position is invalid if it's out of the given coordinate system, which means that either x or y are greater than 10 or less than 0*/
	if (tileToCheck.getXCoordinate() < 0 || tileToCheck.getXCoordinate() > 10 || tileToCheck.getYCoordinate() < 0 || tileToCheck.getYCoordinate() > 10)
		return false;
	return true;
}

std::vector<Tile> Repository::getAllTilesScanned()
{
	return this->checkedTiles;
}
