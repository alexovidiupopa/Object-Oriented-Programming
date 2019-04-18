#include "Tape.h"
#include <stdlib.h>
#include <sstream>
#include <string>
#include "Exceptions.h"
Tape::Tape()
{
}

Tape::Tape(std::string& title, std::string& filmedAt, std::string& creationDate, std::string &footagePreview, int accessCount)
{
	this->title = title;
	this->filmedAt = filmedAt;
	this->creationDate = creationDate;
	this->accessCount = accessCount;
	this->footagePreview = footagePreview;
}


std::string Tape::getTitle()
{
	return title;
}

std::string Tape::getFilmedAt()
{
	return filmedAt;
}

std::string Tape::getCreationDate()
{
	return creationDate;
}

std::string Tape::getFootagePreview()
{
	return footagePreview;
}

int Tape::getAccessCount()
{
	return accessCount;
}

void Tape::setTitle(std::string newTitle)
{
	this->title = newTitle;
}

void Tape::setFilmedAt(std::string filmedAt)
{
	this->filmedAt = filmedAt;
}

void Tape::setCreationDate(std::string creationDate)
{
	this->creationDate = creationDate;
}

void Tape::setFootagePreview(std::string footagePreview)
{
	this->footagePreview = footagePreview;
}

void Tape::setAccessCount(int newCount)
{
	accessCount = newCount;
}

Tape & Tape::operator=(const Tape & tapeToCheck)
{
	this->title = tapeToCheck.title;
	this->filmedAt = tapeToCheck.filmedAt;
	this->footagePreview = tapeToCheck.footagePreview;
	this->creationDate = tapeToCheck.creationDate;
	this->accessCount = tapeToCheck.accessCount;
	return *this;
}

bool Tape::operator==(const Tape & tapeToCheck)
{
	return this->title == tapeToCheck.title;
}


Tape::~Tape()
{
	
}

std::vector<std::string> tokenizeInput(std::string inputString, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream stringStream(inputString);
	std::string token;
	while (getline(stringStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

std::ostream & operator<<(std::ostream & outputStream, const Tape &tapeToPrint)
{
	outputStream << tapeToPrint.title << "," << tapeToPrint.filmedAt << "," << tapeToPrint.creationDate << ", " << tapeToPrint.accessCount << "," << tapeToPrint.footagePreview << "\n";
	return outputStream;
}

std::istream & operator>>(std::istream & inputStream, Tape & tapeToRead)
{
	std::string line;
	getline(inputStream, line);
	std::vector<std::string>tokens = tokenizeInput(line,',');
	if (tokens.size() != 5)
		return inputStream;
	tapeToRead.setTitle(tokens[0]);
	tapeToRead.setFilmedAt(tokens[1]);
	tapeToRead.setCreationDate(tokens[2]);
	tapeToRead.setAccessCount(std::stoi(tokens[3]));
	tapeToRead.setFootagePreview(tokens[4]);
	return inputStream;
}

