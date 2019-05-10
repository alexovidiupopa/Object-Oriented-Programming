#pragma once
#include "Controller.h"
class UI
{
private: 
	Controller controller{};
	void addPainting();
	void removePainting();
	void listGallery();
	void listSpecial();
	void undo();
	void printMenu();
public:
	UI();
	void run();
	~UI();
};

