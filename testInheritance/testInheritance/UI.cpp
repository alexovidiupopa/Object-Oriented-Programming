#include "UI.h"
#include <iostream>

void UI::addPainting()
{
	std::string title;
	std::string artist;
	int year;
	std::cin.get();
	std::getline(std::cin, title);
	std::getline(std::cin, artist);
	std::cin >> year;
	this->controller.addPainting(artist, title, year);
}

void UI::removePainting()
{
	std::string title;
	std::string artist;
	int year;
	std::cin.get();
	std::getline(std::cin, title);
	std::getline(std::cin, artist);
	std::cin >> year;
	this->controller.removePainting(artist, title, year);
}

void UI::listGallery()
{
	std::vector<Painting> gallery = this->controller.getAll();
	std::cout << "Gallery paintings:"<<std::endl;
	for (auto painting : gallery) {
		std::cout << "artist:" << painting.getArtist() << " " << "title: " << painting.getTitle() << " " << "year:" << painting.getYear() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void UI::listSpecial()
{
	std::vector<Painting> gallery = this->controller.getSpecialStorage();
	std::cout << "Special storage paintings:"<<std::endl;
	for (auto painting : gallery) {
		std::cout <<"artist:"<< painting.getArtist() << " " << "title: "<<painting.getTitle() << " " <<"year:"<< painting.getYear() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void UI::undo()
{
	this->controller.undo();
}

void UI::printMenu()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "0-exit" << std::endl;
	std::cout << "1-add" << std::endl;
	std::cout << "2-remove" << std::endl;
	std::cout << "3-list both galleries" << std::endl;
	std::cout << "4-undo" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

UI::UI()
{
}

void UI::run()
{
	this->controller.addPainting("Mona Lisa","DaVinci",1400 );
	this->controller.addPainting("Starry Night", "Van Gogh", 1655);
	this->controller.addPainting("painting_knowledge_exhausted", "faimous_painter", 999);
	int cmd;
	std::cout << "Welcome"<<std::endl;
	while (true) {
		printMenu();
		std::cout << ">>";
		std::cin >> cmd;
		if (cmd == 1) {
			addPainting();
			
		}
		else if (cmd == 2) {
			removePainting();
		
		}
		else if (cmd == 3) {
			listGallery();
			listSpecial();
		}
		else if (cmd == 4) {
			undo();
			
		}
		else if (cmd == 0) {
			return;
		}
	}
}


UI::~UI()
{
}
