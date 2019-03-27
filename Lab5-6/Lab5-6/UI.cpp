#include "UI.h"
#include <iostream>
#include <stdlib.h>
bool UI::addTape(char command[])
{
	//command;
	char title[21], filmedAt[41], creationDate[21], footagePreview[21],accessCount[21];
	command = strtok(NULL, ", ");
	if (command == NULL)
		return false;
	strcpy(title, command);
	std::cout << title;
	command = strtok(NULL, ", ");
	if (command == NULL)
		return false;
	strcpy(filmedAt, ", ");
	std::cout << filmedAt;
	command = strtok(NULL, ", ");
	if (command == NULL)
		return false;
	strcpy(creationDate, ", ");
	command = strtok(NULL, ", ");
	if (command == NULL)
		return false;
	strcpy(accessCount, command);
	command = strtok(NULL, ", ");
	if (command == NULL)
		return false;
	strcpy(footagePreview, ", ");
	command = strtok(NULL, ", ");
	if (command != NULL)
		return false;
	return this->controller->addTape(title, filmedAt, creationDate, footagePreview, atoi(accessCount));
}

bool UI::list(char command[])
{
	command = strtok(NULL, " ");
	if (command != NULL)
		return false;
	//std::cout << "here";
	char tapes[1001];
	tapes[0] = 0;
	this->controller->listTapes(tapes);
	std::cout << tapes;
	return true;
}

UI::UI(Controller * controller)
{
	this->controller = controller;
}

void UI::run()
{
	bool readCommand = true;
	while (readCommand)
	{
		char command[101];
		std::cin.getline(command,101);
		char *splitCommand;
		splitCommand = strtok(command, " ");
		bool validCommand = false;
		strcpy(command, splitCommand);

		if (strcmp(command, "add")==0) {
			validCommand = this->addTape(command);
		}
		else if (strcmp(command, "list") == 0) {
			validCommand = this->list(command);
		}
		else if (strcmp(command, "exit") == 0) {
			readCommand = false;
		}
		if (!validCommand)
			std::cout << "Invalid command";
	}
}
