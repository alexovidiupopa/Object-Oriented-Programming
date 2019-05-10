#include "Painting.h"


std::string Painting::getTitle()
{
	return this->title;
}

std::string Painting::getArtist()
{
	return this->artist;
}

int Painting::getYear()
{
	return this->year;
}

Painting::~Painting()
{
}
