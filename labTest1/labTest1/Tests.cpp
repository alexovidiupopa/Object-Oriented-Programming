#include "Tests.h"
#include "Controller.h"
#include <cassert>

void testMoveRobot() {
	Repository testRepo{};
	Controller testController{ &testRepo };
	assert(testRepo.moveRobot(Tile{ 1,2 }));
	assert(!testRepo.moveRobot(Tile{ -1,-1 }));	
	char testDirection[10] = "up";
	assert(testController.moveRobot(testDirection));
	strcpy(testDirection, "down");
	assert(!testController.moveRobot(testDirection));
	strcpy(testDirection, "right");
	assert(testController.moveRobot(testDirection));
}

void testPercentage() {
	Repository testRepo{};
	Controller testController{ &testRepo };
	assert(testRepo.moveRobot(Tile{ 1,2 }));
	assert(int(testController.percentageOfScannedTiles()) == 0);
	char testDirection[10] = "up";
	assert(testController.moveRobot(testDirection));
	assert(int(testController.percentageOfScannedTiles()) == 1);
}
void testAll()
{
	testMoveRobot();
	testPercentage();
}

