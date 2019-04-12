#include "UI.h"
#include <iostream>
#include <stdlib.h>
bool UI::addTape(char command[])
{
	char title[21], filmedAt[41], creationDate[21], footagePreview[21],accessCount[21];
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(title, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(filmedAt, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(creationDate, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(accessCount, command);
	integerAccessCount = atoi(accessCount);
	if (integerAccessCount == 0)
		return false;
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(footagePreview, command);
	command = strtok(NULL, ",");
	if (command != NULL)
		return false;
	return this->controller.addTape(title, filmedAt, creationDate, footagePreview, atoi(accessCount));
}

bool UI::list(char command[])
{
	command = strtok(NULL, ",");
	if (command == NULL) {
		char tapes[1001];
		tapes[0] = 0;
		this->controller.listTapes(tapes);
		std::cout << tapes;
		return true;
	}
	return false;
}

bool UI::removeTape(char command[])
{
	char title[31];
	command = strtok(NULL, " ");
	if (command == NULL)
		return false;
	strcpy(title, command);
	command = strtok(NULL, " ");
	if (command != NULL)
		return false;
	return this->controller.removeTape(title);
}

bool UI::updateTape(char command[])
{
	char title[21], filmedAt[41], creationDate[21], footagePreview[21], accessCount[21];
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(title, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(filmedAt, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(creationDate, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(accessCount, command);
	integerAccessCount = atoi(accessCount);
	if (integerAccessCount == 0)
		return false;
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(footagePreview, command);
	command = strtok(NULL, ",");
	if (command != NULL)
		return false;
	return this->controller.updateTape(title, filmedAt, creationDate, footagePreview, atoi(accessCount));
}

bool UI::listWhenInUserMode(char command[])
{
	char filmedAt[31], accessCount[31];
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(filmedAt, " ");
	strcat(filmedAt, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		return false;
	strcpy(accessCount, command);
	integerAccessCount = atoi(accessCount);
	if (integerAccessCount == 0)
		return false;
	char tapes[1001];
	tapes[0] = 0;
	this->controller.listTapesFilmedAtLessThanCount(tapes, filmedAt, integerAccessCount);
	std::cout << tapes;
	return true;
}

bool UI::nextInPlaylist(char command[])
{
	
	Tape currentTape = this->controller.nextInPlaylist();
	//std::cout << currentTape.getTitle() << currentTape.getFilmedAt() << currentTape.getCreationDate() << " " << currentTape.getAccessCount() << currentTape.getFootagePreview() << "\n";
	char tapeToPrint[1001];
	tapeToPrint[0] = 0;
	currentTape.toString(tapeToPrint);
	std::cout << tapeToPrint;
	return true;
}

bool UI::saveToPlaylist(char command[])
{
	char title[21];
	command = strtok(NULL, " ");
	strcpy(title, command);
	return this->controller.saveToPlaylist(title);
}

bool UI::printPlaylist(char command[])
{
	char playlist[1001];
	playlist[0] = 0;
	this->controller.listPlaylist(playlist);
	std::cout << playlist;
	return true;
}

void UI::initializeIndexForPlaylistIterating()
{
	this->controller.initializeIndex();
}

void UI::run()
{
	bool readCommand = true;
	bool validCommand = true;
	char command[101];
	char *splitCommand;
	this->applicationMode = 'X';
	initializeIndexForPlaylistIterating();
	while (readCommand)
	{
		std::cin.getline(command, 101);
		if (strcmp(command, "mode A") == 0)
		{
			this->applicationMode = 'A';
		}
		else if (strcmp(command, "mode B") == 0)
		{
			this->applicationMode = 'B';
		}
		else {
			switch (this->applicationMode) {
			case 'A':
				
				splitCommand = strtok(command, " ");

				validCommand = false;

				strcpy(command, splitCommand);

				if (strcmp(command, "add") == 0) {
					validCommand = this->addTape(command);
				}
				else if (strcmp(command, "delete") == 0) {
					validCommand = this->removeTape(command);
				}
				else if (strcmp(command, "update") == 0)
				{
					validCommand = this->updateTape(command);
				}
				else if (strcmp(command, "list") == 0) {
					validCommand = this->list(command);
				}
				else if (strcmp(command, "exit") == 0) {
					return;
				}
				if (!validCommand) {
					//std::cout << "Invalid command\n";
					
				}
			case 'B':
				
				splitCommand = strtok(command, " ");

				validCommand = false;

				strcpy(command, splitCommand);

				if (strcmp(command, "mylist") == 0)
				{
					validCommand = this->printPlaylist(command);
				}
				else if (strcmp(command, "next") == 0)
				{
					validCommand = this->nextInPlaylist(command);
				}
				else if (strcmp(command, "list") == 0)
				{
					validCommand = this->listWhenInUserMode(command);
				}
				else if (strcmp(command, "save") == 0)
				{
					validCommand = this->saveToPlaylist(command);
				}
				else if (strcmp(command, "exit") == 0)
				{
					return;
				}
				if (!validCommand) {
					//std::cout << "Invalid command\n";
				}
			case 'X':
				if (strcmp(command, "exit") == 0)
					return;
			default:
				continue;
			}
		}
	}
}
