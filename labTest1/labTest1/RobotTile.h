#pragma once

class Tile {

private: 
	int xCoordinate, yCoordinate;
public: 
	Tile(int xCoordinate, int yCoordinate);
	~Tile();
	int getXCoordinate();
	int getYCoordinate();

	void setXCoordinate(int newXCoordinate);
	void setYCoordinate(int newYCoordinate);

	

};