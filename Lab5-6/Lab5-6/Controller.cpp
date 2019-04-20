#include "Controller.h"
#include <iostream>
#include <algorithm>
void Controller::addTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount)
{
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	this->repository.addTapeToRepository(TapeToAdd);
	this->saveRepository();
}

void Controller::removeTape(std::string givenTitle)
{
	this->repository.removeTapeFromRepo(givenTitle);
	this->saveRepository();
}

void Controller::updateTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount)
{
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
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
	return this->repository.getPlaylist();
}

void Controller::saveToPlaylist(std::string givenTitle)
{
	this->repository.saveTape(givenTitle);
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

void Controller::setRepository(std::string path)
{
	this->repository.setPath(path);
	this->repository.loadRepository();
}

void Controller::saveRepository()
{
	this->repository.saveRepository();
}




