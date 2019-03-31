#pragma once
#include "Controller.h"
class UI {

private:

	Controller controller;
	char applicationMode;
	bool addTape(char command[]);
	bool list(char command[]);
	bool removeTape(char command[]);
	bool updateTape(char command[]);

	bool listWhenInUserMode(char command[]);
	bool nextInPlaylist(char command[]);
	bool saveToPlaylist(char command[]);
	bool printPlaylist(char command[]);

	void initializeIndexForPlaylistIterating();
public:
	UI(const Controller& controller) : controller(controller) {};
	void run();
	
};