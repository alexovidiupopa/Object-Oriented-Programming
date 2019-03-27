#include "Repository.h"
#include <stdlib.h>
#include <iostream>
void Repository::resize()
{
	capacity *= 2;
	Tape* temporaryRepo = new Tape[capacity];
	for (int i = 0; i < length; i++) {
		temporaryRepo[i] = tapes[i];
	}
	delete[]tapes;
	tapes = temporaryRepo;
}

int Repository::searchForTape(char title[])
{
	for (int i = 0; i < length; i++)
		if (strcmp(tapes[i].getTitle(),title)==0)
			return i;
	return -1;
}

Repository::Repository()
{
	length = 0;
	capacity = 1;
	tapes = new Tape[1];
}

bool Repository::addTapeToRepository(Tape tapeToAdd)
{
	if (searchForTape(tapeToAdd.getTitle())!=-1)
		return false;
	if (length == capacity)
		resize();
	tapes[length++] = tapeToAdd;
	return true;
}

bool Repository::removeTapeFromRepo(char title[])
{
	int index = searchForTape(title);
	if (index==-1)
		return false;
	length--;
	for (int i = index; i < length; i++) {
		tapes[i] = tapes[i + 1];
	}
	return true;

}

bool Repository::updateTapeInRepo(Tape tapeToUpdate)
{
	int index = searchForTape(tapeToUpdate.getTitle());
	if (index == -1)
		return false;
	tapes[index] = tapeToUpdate;
}

void Repository::getAllTapes(char tapesToGet[])
{
	for (int i = 0; i < length; i++) {
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
	}
}

Repository* Repository::copyRepository()
{
	Repository* copy=new Repository();
	copy->capacity = capacity;
	copy->length = length;
	for (int i = 0; i < length; i++)
		copy->tapes[i] = tapes[i];
	return copy;
}

Repository::~Repository()
{
	delete[] tapes;
}
