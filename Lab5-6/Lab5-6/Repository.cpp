#include "Repository.h"
#include <stdlib.h>
#include <iostream>

int Repository::searchForTape(char title[])
{
	GenericElement* tapes = this->tapes.getAllElements();
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

DynamicVector Repository::getAllTapes()
{
	/*for (int i = 0; i < length; i++) {
		char auxiliary[21];
		auxiliary[0] = 0;
		strcat(tapesToGet, tapes[i].getTitle());
		strcat(tapesToGet, " ");
		strcat(tapesToGet, tapes[i].getFilmedAt());
		strcat(tapesToGet, " ");
		strcat(tapesToGet, tapes[i].getCreationDate());
		strcat(tapesToGet, " ");
		_itoa(tapes[i].getAccessCount(), auxiliary, 10);
		strcat(tapesToGet, auxiliary);
		strcat(tapesToGet, " ");
		strcat(tapesToGet, tapes[i].getFootagePreview());
		strcat(tapesToGet, "\n");
	}*/
	return this->tapes;
}
