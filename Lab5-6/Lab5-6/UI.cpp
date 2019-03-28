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
	command = strtok(NULL, " ");
	if (command != NULL)
		return false;
	char tapes[1001];
	tapes[0] = 0;
	this->controller.listTapes(tapes);
	std::cout << tapes;
	return true;
}

bool UI::removeTape(char command[])
{
	char title[21];
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
	command = strtok(NULL, ", =");
	if (command != NULL)
		return false;
	return this->controller.updateTape(title, filmedAt, creationDate, footagePreview, atoi(accessCount));
}

void UI::run()
{
	bool readCommand = true;
	char mode[21];
	std::cin.getline(mode, 21);
	if (strcmp(mode, "mode A") == 0) {
		while (readCommand)
		{
			char command[101];
			std::cin.getline(command, 101);
			char *splitCommand;
			splitCommand = strtok(command, " ");
			
			bool validCommand = false;

			strcpy(command, splitCommand);

			if (strcmp(command, "add") == 0) {
				validCommand = this->addTape(command);
			}
			else if (strcmp(command, "remove") == 0) {
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
			if (!validCommand)
				std::cout << "Invalid command\n";
		}
	}
	else {
		while (readCommand)
		{
			char command[101];
			std::cin.getline(command, 101);
			char *splitCommand;
			splitCommand = strtok(command, " ");
			bool validCommand = false;
			strcpy(command, splitCommand);
			if (strcmp(command, "exit") == 0) {
				return;
			}
			else {
				continue;
			}
		}
	}
}
