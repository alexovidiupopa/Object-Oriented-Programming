#include "Tape.h"

Tape::Tape()
{
}

Tape::Tape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	strcpy(title, givenTitle);
	strcpy(filmedAt, givenFilmedAt);
	strcpy(creationDate, givenCreationDate);
	strcpy(footagePreview, givenFootagePreview);
	accessCount = givenAccessCount;
}
char * Tape::getTitle()
{
	return title;
}

const char * Tape::getFilmedAt()
{
	return filmedAt;
}

const char * Tape::getCreationDate()
{
	return creationDate;
}

const char * Tape::getFootagePreview()
{
	return footagePreview;
}

int Tape::getAccessCount()
{
	return accessCount;
}

void Tape::setTitle(char newTitle[])
{
	strcpy(title, newTitle);
}

void Tape::setFilmedAt(char filmedAt[])
{
	strcpy(filmedAt, filmedAt);
}

void Tape::setCreationDate(char creationDate[])
{
	strcpy(creationDate, creationDate);
}

void Tape::setFootagePreview(char footagePreview[])
{
	strcpy(footagePreview, footagePreview);
}

void Tape::setAccessCount(int newCount)
{
	accessCount = newCount;
}

Tape & Tape::operator=(const Tape & tapeToCheck)
{
	strcpy(this->title, tapeToCheck.title);
	strcpy(this->filmedAt, tapeToCheck.filmedAt);
	strcpy(this->creationDate, tapeToCheck.creationDate);
	strcpy(this->footagePreview, tapeToCheck.footagePreview);
	this->accessCount = tapeToCheck.accessCount;
	return *this;
}

bool Tape::operator==(const Tape & tapeToCheck)
{
	return strcmp(this->title, tapeToCheck.title) == 0;
}

Tape::~Tape()
{
	
}
