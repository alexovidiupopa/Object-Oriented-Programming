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

void Controller::listTapes(char tapesToPrint[])
{
	DynamicVector<Tape>tapesDynamicVector = this->repository.getAllTapes();
	Tape* tapesFromTheRepository = tapesDynamicVector.getAllElements();
	for (int i = 0; i < tapesDynamicVector.getSize(); i++)
	{
		tapesFromTheRepository[i].toString(tapesToPrint);
	}
	
}

void Controller::listTapesFilmedAtLessThanCount(char tapesToPrint[], char givenFilmedAt[], int givenAccessCount)
{
	DynamicVector<Tape> tapesRepository = this->repository.getAllTapes();
	Tape* tapesFromTheRepository = tapesRepository.getAllElements();
	int length = tapesRepository.getSize();
	for (int i = 0; i < length; i++) {
		if (strcmp(tapesFromTheRepository[i].getFilmedAt(), givenFilmedAt) == 0 && tapesFromTheRepository[i].getAccessCount() < givenAccessCount)
		{
			tapesFromTheRepository[i].toString(tapesToPrint);
		}
	}
}

void Controller::listPlaylist(char playlistToBeListed[])
{
	DynamicVector<Tape> playlistRepository = this->repository.getPlaylist();
	Tape* playlistFromRepository = playlistRepository.getAllElements();
	int length = playlistRepository.getSize();
	for (int i = 0; i < length; i++) {
		playlistFromRepository[i].toString(playlistToBeListed);
	}
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
	DynamicVector<Tape> tapesRepository = this->repository.getAllTapes();
	if (this->indexForPlaylistIterating == tapesRepository.getSize())
		this->indexForPlaylistIterating = 0;
	Tape* tapes = tapesRepository.getAllElements();
	this->indexForPlaylistIterating++;
	return tapes[this->indexForPlaylistIterating -1];
}


