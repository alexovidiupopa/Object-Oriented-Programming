#include "RobotTile.h"

Tile::Tile(int xCoordinate, int yCoordinate)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
}

Tile::~Tile()
{
}

int Tile::getXCoordinate()
{
	return this->xCoordinate;
}

int Tile::getYCoordinate()
{
	return this->yCoordinate;
}

void Tile::setXCoordinate(int newXCoordinate)
{
	this->xCoordinate = newXCoordinate;
}

void Tile::setYCoordinate(int newYCoordinate)
{
	this->yCoordinate = newYCoordinate;
}
