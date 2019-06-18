#include "Writer.h"



Writer::Writer()
{
}


Writer::~Writer()
{
}

string Writer::getName() const
{
    return name;
}

void Writer::setName(string name)
{
    this->name = name;
}

string Writer::getExpertise() const
{
    return expertise;
}

void Writer::setExpertise(string expertise)
{
    this->expertise = expertise;
}

string Writer::toString()
{
	return name + ";" + expertise + "\n";
}

