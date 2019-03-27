#pragma once
#include "Repository.h"
#include "Validator.h"

class Controller {

private:

	Repository* repository;
	Validator* validator;

public:

	Controller(Repository* repository, Validator* validator);

	bool addTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount);

	bool removeTape(char givenTitle[]);

	bool updateTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount);

	void listTapes(char tapesToPrint[]);

	~Controller();
};