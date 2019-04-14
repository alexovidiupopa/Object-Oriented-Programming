#include "UI.h"
#include <iostream>
#include <stdlib.h>
bool UI::addTape(char command[])
{
	char title[21], filmedAt[41], creationDate[21], footagePreview[21],accessCount[21];
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(title, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(filmedAt, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(creationDate, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(accessCount, command);
	integerAccessCount = atoi(accessCount);
	if (integerAccessCount == 0)
		throw UserInputException("Input error");
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(footagePreview, command);
	command = strtok(NULL, ",");
	if (command != NULL)
		throw UserInputException("Input error");
	return this->controller.addTape(title, filmedAt, creationDate, footagePreview, atoi(accessCount));
}

bool UI::list(char command[])
{
	command = strtok(NULL, ",");
	if (command == NULL) {
		
		std::vector<Tape> tapes = this->controller.listTapes();
		for (auto it : tapes)
			std::cout << it;
		return true;
	}
	throw UserInputException("Input error");
	
}

bool UI::removeTape(char command[])
{
	char title[31];
	command = strtok(NULL, " ");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(title, command);
	command = strtok(NULL, " ");
	if (command != NULL)
		throw UserInputException("Input error");
	return this->controller.removeTape(title);
}

bool UI::updateTape(char command[])
{
	char title[21], filmedAt[41], creationDate[21], footagePreview[21], accessCount[21];
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(title, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(filmedAt, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(creationDate, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(accessCount, command);
	integerAccessCount = atoi(accessCount);
	if (integerAccessCount == 0)
		throw UserInputException("Input error");
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(footagePreview, command);
	command = strtok(NULL, ",");
	if (command != NULL)
		throw UserInputException("Input error");
	return this->controller.updateTape(title, filmedAt, creationDate, footagePreview, atoi(accessCount));
}

bool UI::listWhenInUserMode(char command[])
{
	char filmedAt[31], accessCount[31];
	int integerAccessCount;
	std::cout << "saddaad";
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(filmedAt, " ");
	strcat(filmedAt, command);
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(accessCount, command);
	integerAccessCount = atoi(accessCount);
	if (integerAccessCount == 0)
		throw UserInputException("Input error");
	std::vector<Tape> tapes = this->controller.listTapesFilmedAtLessThanCount(filmedAt, integerAccessCount);
	for (auto it : tapes)
		std::cout << it;
	return true;
}

bool UI::nextInPlaylist(char command[])
{
	
	Tape currentTape = this->controller.nextInPlaylist();
	std::cout << currentTape;
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
	std::vector<Tape> playlist;
	playlist = this->controller.listPlaylist();
	for (auto it : playlist)
		std::cout << it;
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
					try { 
						validCommand = this->addTape(command); 
					}
					catch (RepositoryException& re) {
						std::cout << re.getMessage() << std::endl;
					}
					catch (UserInputException& ue) {
						std::cout << ue.getMessage() << std::endl;
					}
					
				}
				else if (strcmp(command, "delete") == 0) {
					try {
						validCommand = this->removeTape(command);
					}
					catch (RepositoryException& re) {
						std::cout << re.getMessage() << std::endl;
					}
					catch (UserInputException& ue) {
						std::cout << ue.getMessage() << std::endl;
					}
				}
				else if (strcmp(command, "update") == 0)
				{
					try {
						validCommand = this->updateTape(command);

					}
					catch (RepositoryException& re) {
						std::cout << re.getMessage() << std::endl;
					}
					catch (UserInputException& ue) {
						std::cout << ue.getMessage() << std::endl;
					}
				}
				else if (strcmp(command, "list") == 0) {
					validCommand = this->list(command);
					continue;
				}
				else if (strcmp(command, "exit") == 0) {
					return;
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
					try {
						validCommand = this->listWhenInUserMode(command);
					}
					catch (UserInputException& ue) {
						std::cout << ue.getMessage() << std::endl;
					}
				}
				else if (strcmp(command, "save") == 0)
				{
					validCommand = this->saveToPlaylist(command);
				}
				else if (strcmp(command, "exit") == 0)
				{
					return;
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
