#include "UI.h"
#include <stdlib.h>

void UI::addTape(char command[])
{
	std::string title, filmedAt, creationDate, footagePreview, accessCount;
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	title = command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	filmedAt = command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	creationDate = command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	accessCount = command;
	integerAccessCount = std::stoi(accessCount);
	if (integerAccessCount == 0)
		throw UserInputException("Input error");
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	footagePreview = command;
	command = strtok(NULL, ",");
	if (command != NULL)
		throw UserInputException("Input error");
	this->controller.addTape(title, filmedAt, creationDate, footagePreview, integerAccessCount);
}

void UI::list(char command[])
{
	command = strtok(NULL, ",");
	if (command == NULL) {
		
		std::vector<Tape> tapes = this->controller.listTapes();
		for (auto tapeInRepository : tapes)
			std::cout << tapeInRepository;
		return;
	}
	throw UserInputException("Input error");
	
}

void UI::removeTape(char command[])
{
	char title[31];
	command = strtok(NULL, " ");
	if (command == NULL)
		throw UserInputException("Input error");
	strcpy(title, command);
	command = strtok(NULL, " ");
	if (command != NULL)
		throw UserInputException("Input error");
	this->controller.removeTape(title);
}

void UI::updateTape(char command[])
{
	std::string title, filmedAt, creationDate, footagePreview, accessCount;
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	title = command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	filmedAt = command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	creationDate = command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	accessCount = command;
	integerAccessCount = std::stoi(accessCount);
	if (integerAccessCount == 0)
		throw UserInputException("Input error");
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	footagePreview = command;
	command = strtok(NULL, ",");
	if (command != NULL)
		throw UserInputException("Input error");
	this->controller.updateTape(title, filmedAt, creationDate, footagePreview, integerAccessCount);
}

void UI::listWhenInUserMode(char command[])
{
	std::string filmedAt, accessCount;
	int integerAccessCount;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	filmedAt = "";
	filmedAt += command;
	command = strtok(NULL, ",");
	if (command == NULL)
		throw UserInputException("Input error");
	accessCount = command;
	integerAccessCount = std::stoi(accessCount);
	if (integerAccessCount == 0)
		throw UserInputException("Input error");
	std::vector<Tape> tapes = this->controller.listTapesFilmedAtLessThanCount(filmedAt, integerAccessCount);
	for (auto tapeInRepository : tapes)
		std::cout << tapeInRepository;
}

void UI::nextInPlaylist(char command[])
{
	
	Tape currentTape = this->controller.nextInPlaylist();
	std::cout << currentTape;
}

void UI::saveToPlaylist(char command[])
{
	char title[21];
	command = strtok(NULL, " ");
	strcpy(title, command);
	this->controller.saveToPlaylist(title);
}

void UI::printPlaylist(char command[])
{
	std::vector<Tape> playlist;
	playlist = this->controller.listPlaylist();
	for (auto tapeInRepository : playlist)
		std::cout << tapeInRepository;
}

void UI::openPlaylistWithCorrectApp()
{
	this->controller.openPlaylist();
}

void UI::initializeIndexForPlaylistIterating()
{
	this->controller.initializeIndex();
}

void UI::run()
{
	bool readCommand = true;
	bool validCommand = true;
	char command[201];
	char *splitCommand;
	this->applicationMode = 'X';
	initializeIndexForPlaylistIterating();
	while (readCommand)
	{
		std::cin.getline(command, 201);
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
						this->addTape(command); 
					}
					catch (RepositoryException& repositoryError) {
						std::cout << repositoryError.getMessage() << std::endl;
					}
					catch (UserInputException& UserInputError) {
						std::cout << UserInputError.getMessage() << std::endl;
					}
					catch (ValidatorException& validationError) {
						std::cout << validationError.getMessage() << std::endl;
					}
					
				}
				else if (strcmp(command, "delete") == 0) {
					try {
						this->removeTape(command);
					}
					catch (RepositoryException& repositoryError) {
						std::cout << repositoryError.getMessage() << std::endl;
					}
					catch (UserInputException& UserInputError) {
						std::cout << UserInputError.getMessage() << std::endl;
					}
					catch (ValidatorException& validationError) {
						std::cout << validationError.getMessage() << std::endl;
					}
				}
				else if (strcmp(command, "update") == 0)
				{
					try {
						this->updateTape(command);

					}
					catch (RepositoryException& repositoryError) {
						std::cout << repositoryError.getMessage() << std::endl;
					}
					catch (UserInputException& UserInputError) {
						std::cout << UserInputError.getMessage() << std::endl;
					}
					catch (ValidatorException& validationError) {
						std::cout << validationError.getMessage() << std::endl;
					}
				}
				else if (strcmp(command, "list") == 0) {
					this->list(command);
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
					this->printPlaylist(command);
				}
				else if (strcmp(command, "next") == 0)
				{
					this->nextInPlaylist(command);
				}
				else if (strcmp(command, "list") == 0)
				{
					try {
						this->listWhenInUserMode(command);
					}
					catch (UserInputException& UserInputError) {
						std::cout << UserInputError.getMessage() << std::endl;
					}
				}
				else if (strcmp(command, "open") == 0) {
					this->openPlaylistWithCorrectApp();
				}
				else if (strcmp(command, "save") == 0)
				{
					try {
						this->saveToPlaylist(command);
					}
					catch (FileException &fileError) {
						std::cout << fileError.getMessage() << std::endl;
					}
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
