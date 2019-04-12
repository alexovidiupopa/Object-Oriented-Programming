#include "Repository.h"
#include <stdlib.h>
#include <iostream>

int Repository::searchForTape(char title[])
{
	Tape* tapes = this->tapes.getAllElements();
	int length = this->tapes.getSize();
	for (int i = 0; i < length; i++)
		if (strcmp(tapes[i].getTitle(),title)==0)
			return i;
	return -1;
}

bool Repository::addTapeToRepository(Tape tapeToAdd)
{
	if (searchForTape(tapeToAdd.getTitle())!=-1)
		return false;
	this->tapes.addToDynamicVector(tapeToAdd);
	return true;
}

bool Repository::removeTapeFromRepo(char title[])
{
	int index = searchForTape(title);
	if (index==-1)
		return false;
	this->tapes.removeFromDynamicVector(index);
	return true;

}

bool Repository::updateTapeInRepo(Tape tapeToUpdate)
{
	int index = searchForTape(tapeToUpdate.getTitle());
	if (index == -1)
		return false;
	this->tapes.updateInDynamicVector(index,tapeToUpdate);
	return true;
}

DynamicVector<Tape>Repository::getAllTapes()
{
	return this->tapes;
}

DynamicVector<Tape> Repository::getPlaylist()
{
	return this->playlist;
}

bool Repository::saveTape(char givenTitle[])
{
	int index = searchForTape(givenTitle);
	if (index == -1)
		return false;
	Tape* tapes = this->tapes.getAllElements();
	this->playlist.addToDynamicVector(tapes[index]);
	return true;
}
