#include "Repository.h"
#include <stdlib.h>
#include <iostream>


int Repository::searchForTape(std::string title)
{
	std::vector<Tape> tapes = this->tapes;
	for (int i = 0; i < this->tapes.size(); i++)
		if (tapes[i].getTitle()==title)
			return i;
	return -1;
}

void Repository::addTapeToRepository(Tape tapeToAdd)
{
	if (searchForTape(tapeToAdd.getTitle())!=-1)
		throw RepositoryException("Tape already exists");
	this->tapes.push_back(tapeToAdd);
	
}

void Repository::removeTapeFromRepo(std::string title)
{
	int index = searchForTape(title);
	if (index==-1)
		throw RepositoryException("Tape doesn't exist");
	this->tapes.erase(this->tapes.begin()+index);
}

void Repository::updateTapeInRepo(Tape tapeToUpdate)
{
	int index = searchForTape(tapeToUpdate.getTitle());
	if (index == -1)
		throw RepositoryException("Tape doesn't exist");
	this->tapes[index]=tapeToUpdate;
}

std::vector<Tape>Repository::getAllTapes()
{
	return this->tapes;
}


