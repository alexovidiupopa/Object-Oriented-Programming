#include "Controller.h"
#include <iostream>


/*Controller::Controller(Repository & repository, Validator & validator)
{
	this->repository = repository;
	this->validator = validator;
}*/

bool Controller::addTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	/*if (!this->validator.validateData(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount))
		return false;*/

	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	return this->repository.addTapeToRepository(TapeToAdd);
}

bool Controller::removeTape(char givenTitle[])
{
	return this->repository.removeTapeFromRepo(givenTitle);
}

bool Controller::updateTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	/*if (!this->validator.validateData(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount))
		return false;*/

	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	return this->repository.updateTapeInRepo(TapeToAdd);
}

void Controller::listTapes(char tapesToPrint[])
{
	DynamicVector tapesDynamicVector = this->repository.getAllTapes();
	GenericElement* tapesFromTheRepository = tapesDynamicVector.getAllElements();
	for (int i = 0; i < tapesDynamicVector.getSize(); i++)
	{
		char auxiliary[21];
		auxiliary[0] = 0;
		strcat(tapesToPrint, tapesFromTheRepository[i].getTitle());
		//strcat(tapesToPrint, " ");
		strcat(tapesToPrint, tapesFromTheRepository[i].getFilmedAt());
		//strcat(tapesToPrint, " ");
		strcat(tapesToPrint, tapesFromTheRepository[i].getCreationDate());
		strcat(tapesToPrint, " ");
		_itoa(tapesFromTheRepository[i].getAccessCount(), auxiliary, 10);
		strcat(tapesToPrint, auxiliary);
		//strcat(tapesToPrint, " ");
		strcat(tapesToPrint, tapesFromTheRepository[i].getFootagePreview());
		strcat(tapesToPrint, "\n");
	}
	
}

