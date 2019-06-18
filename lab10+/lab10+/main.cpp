#pragma once

#include "lab10.h"
#include <fstream>


int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	
	std::string type, location;
	std::ifstream fileInput("config.txt");
	std::getline(fileInput, type);

	if (type == "memory") {
		Repository repository{};
		FilePlaylist* playlist = new CSVPlaylist{};
		playlist->setFileName("a.csv");
		Validator validator{};
		Controller controller{ repository,playlist,validator };
		lab10 GUI(controller);
		GUI.show();
		return application.exec();
	}
	else {
		fileInput.get();
		std::getline(fileInput, location);
		Repository* repository = new FileRepository { "a.txt" };
		FilePlaylist* playlist = new CSVPlaylist{};
		playlist->setFileName("a.csv");
		Validator validator{};
		Controller controller{ *repository,playlist,validator };
		lab10 GUI(controller);
		GUI.show();
		return application.exec();
	}
	/*FileRepository repository{ "a.txt" };
	FilePlaylist* playlist = new CSVPlaylist{};
	playlist->setFileName("a.csv");
	Validator validator{};
	Controller controller{ repository,playlist,validator };
	lab10 GUI(&controller);
	GUI.show();*/
	
	
	
}

