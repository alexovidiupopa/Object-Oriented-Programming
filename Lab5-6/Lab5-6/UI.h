#pragma once
#include "Controller.h"
class UI {

private:

	Controller controller;
	char mode;
	bool addTape(char command[]);
	bool list(char command[]);
	bool removeTape(char command[]);
	bool updateTape(char command[]);
public:
	UI(const Controller& controller) : controller(controller) {};
	void run();
};