#include "Controller.h"

Controller::Controller(Repository * repository, Validator * validator)
{
	this->repository = repository;
	this->validator = validator;
}

bool Controller::addTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	if (!this->validator->validateData(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount))
		return false;
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	return this->repository->addTapeToRepository(TapeToAdd);
}

bool Controller::removeTape(char givenTitle[])
{
	return false;
}

bool Controller::updateTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	return false;
}

void Controller::listTapes(char tapesToPrint[])
{
	this->repository->getAllTapes(tapesToPrint);
}

Controller::~Controller()
{

}