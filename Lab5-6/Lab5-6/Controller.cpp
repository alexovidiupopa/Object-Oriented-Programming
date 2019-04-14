#include "Controller.h"
#include <iostream>

bool Controller::addTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	return this->repository.addTapeToRepository(TapeToAdd);
}

bool Controller::removeTape(char givenTitle[])
{
	return this->repository.removeTapeFromRepo(givenTitle);
}

bool Controller::updateTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	Tape TapeToAdd(givenTitle, givenFilmedAt, givenCreationDate, givenFootagePreview, givenAccessCount);
	return this->repository.updateTapeInRepo(TapeToAdd);
}

std::vector<Tape> Controller::listTapes()
{
	return this->repository.getAllTapes();
	/*for (auto it : this->repository.getAllTapes())
	{
		it.toString(tapesToPrint);
	}*/
	
}

std::vector<Tape> Controller::listTapesFilmedAtLessThanCount(char givenFilmedAt[], int givenAccessCount)
{
	std::vector<Tape> tapesToPrint;
	for (auto it: this->repository.getAllTapes()) {
		if (strcmp(it.getFilmedAt(), givenFilmedAt) == 0 && it.getAccessCount() < givenAccessCount)
		{
			tapesToPrint.push_back(it);
		}
	}
	return tapesToPrint;
}

std::vector<Tape> Controller::listPlaylist()
{
	std::vector<Tape> playlistToPrint;
	for (auto it : this->repository.getPlaylist()) {
		playlistToPrint.push_back(it);
	}
	return playlistToPrint;
}

bool Controller::saveToPlaylist(char givenTitle[])
{
	return this->repository.saveTape(givenTitle);
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


