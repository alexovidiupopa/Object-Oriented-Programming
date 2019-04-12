#pragma once
#include "Controller.h"
#include <iostream>
class UI {

private: 
	Controller controller;

	void listAllRobots();

	void moveRobot();
public: 

	UI(const Controller &controller) :controller(controller) {};
	~UI();

	void run();
};