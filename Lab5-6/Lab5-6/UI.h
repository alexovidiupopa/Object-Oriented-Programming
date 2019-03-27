#pragma once
#include "Controller.h"
class UI {

private:

	Controller* controller;

	bool addTape(char command[]);
	bool list(char command[]);
public:
	UI(Controller* controller);
	void run();
};