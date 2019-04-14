#include "Repository.h"
#include <stdlib.h>
#include <iostream>


int Repository::searchForTape(char title[])
{
	std::vector<Tape> tapes = this->tapes;
	int length = this->tapes.size();
	/*for (auto it : tapes) {
		if (strcmp(it.getTitle(), title) == 0)
			return;
	}*/
	
	for (int i = 0; i < length; i++)
		if (strcmp(tapes[i].getTitle(),title)==0)
			return i;
	return -1;
}

bool Repository::addTapeToRepository(Tape tapeToAdd)
{
	if (searchForTape(tapeToAdd.getTitle())!=-1)
		throw RepositoryException("Tape already exists");
	this->tapes.push_back(tapeToAdd);
	return true;
}

bool Repository::removeTapeFromRepo(char title[])
{
	int index = searchForTape(title);
	if (index==-1)
		throw RepositoryException("Tape doesn't exist");
	this->tapes.erase(this->tapes.begin()+index);
	return true;

}

bool Repository::updateTapeInRepo(Tape tapeToUpdate)
{
	int index = searchForTape(tapeToUpdate.getTitle());
	if (index == -1)
		throw RepositoryException("Tape doesn't exist");
	this->tapes[index]=tapeToUpdate;
	return true;
}

std::vector<Tape>Repository::getAllTapes()
{
	return this->tapes;
}

std::vector<Tape> Repository::getPlaylist()
{
	return this->playlist;
}

bool Repository::saveTape(char givenTitle[])
{
	int index = searchForTape(givenTitle);
	if (index == -1)
		throw RepositoryException("Tape doesn't exist");
	std::vector<Tape> tapes = this->tapes;
	this->playlist.push_back(tapes[index]);
	return true;
}
