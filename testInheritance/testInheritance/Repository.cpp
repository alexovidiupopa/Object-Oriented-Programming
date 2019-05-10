#include "Repository.h"



void Repository::addPainting(Painting p)
{
	this->paintings.push_back(p);
}

void Repository::removePainting(Painting p)
{
	int i;
	for (i = 0; i < this->paintings.size(); i++) {
		if (this->paintings[i].getArtist() == p.getArtist() && this->paintings[i].getTitle() == p.getTitle())
			break;
	}
	this->paintings.erase(this->paintings.begin() + i);
}

std::vector<Painting> Repository::getAll()
{
	return this->paintings;
}

Repository::~Repository()
{
}
