#include "Controller.h"
#include <iostream>
#include <algorithm>
void Controller::addTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount)
{
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	this->validator.validateData(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	this->repository.addTapeToRepository(TapeToAdd);
	this->saveRepository();
}

void Controller::removeTape(std::string givenTitle)
{
	this->validator.validateData(givenTitle, "randomFilmedAt", "randomDate", "randomPreview", 10);
	this->repository.removeTapeFromRepo(givenTitle);
	this->saveRepository();
}

void Controller::updateTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount)
{
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	this->validator.validateData(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	this->repository.updateTapeInRepo(TapeToAdd);
	this->saveRepository();
}

std::vector<Tape> Controller::listTapes()
{
	return this->repository.getAllTapes();
}

std::vector<Tape> Controller::listTapesFilmedAtLessThanCount(std::string givenFilmedAt, int givenAccessCount)
{
	std::vector<Tape> tapes = this->repository.getAllTapes();
	std::vector<Tape> tapesToPrint;
	tapesToPrint.resize(tapes.size());
	auto lambdaFunctionForFilteringTheTapes = std::copy_if(tapes.begin(), tapes.end(), tapesToPrint.begin(), [givenFilmedAt,givenAccessCount](Tape tape) 
	{return (tape.getFilmedAt() == givenFilmedAt) && (tape.getAccessCount() < givenAccessCount);});
	tapesToPrint.resize(std::distance(tapesToPrint.begin(), lambdaFunctionForFilteringTheTapes));
	return tapesToPrint;
}

std::vector<Tape> Controller::listPlaylist()
{
	return this->playlist->printPlaylistOnScreen();
}

void Controller::saveToPlaylist(std::string givenTitle)
{
	for (auto tape : this->repository.getAllTapes()) {
		if (tape.getTitle() == givenTitle) {
			this->playlist->saveTape(tape);
			this->playlist->writeToFile();
		}
	}
}

void Controller::initializeIndex()
{
	this->indexForPlaylistIterating = 0;
}

Tape Controller::nextInPlaylist()
{
	std::vector<Tape> tapesRepository = this->repository.getAllTapes();
	if (this->indexForPlaylistIterating == tapesRepository.size())
		this->indexForPlaylistIterating = 0;
	this->indexForPlaylistIterating++;
	return tapesRepository[this->indexForPlaylistIterating -1];
}


void Controller::saveRepository()
{
	this->repository.saveRepository();
}

void Controller::openPlaylist()
{
	this->playlist->displayPlaylist();
}




