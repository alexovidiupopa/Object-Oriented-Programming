#pragma once
#include "Controller.h"
class UI {

private:

	Controller controller;
	char applicationMode;
	
	
	void fileLocation(std::string command);
	
	void addTape(char command[]);
	void list(char command[]);
	void removeTape(char command[]);
	void updateTape(char command[]);

	void listWhenInUserMode(char command[]);
	void nextInPlaylist(char command[]);
	void saveToPlaylist(char command[]);
	void printPlaylist(char command[]);


	void initializeIndexForPlaylistIterating();
public:
	UI(const Controller& controller) : controller(controller) {};
	void run();
	
};