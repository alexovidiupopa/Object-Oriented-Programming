#include "Idea.h"



Idea::Idea()
{
}


Idea::~Idea()
{
}

string Idea::getDescription() const
{
    return description;
}

void Idea::setDescription(string description)
{
    this->description = description;
}

string Idea::getStatus() const
{
    return status;
}

void Idea::setStatus(string status)
{
    this->status = status;
}

string Idea::getCreator() const
{
    return creator;
}

void Idea::setCreator(string creator)
{
    this->creator = creator;
}

string Idea::getAct() const
{
    return act;
}

void Idea::setAct(string act)
{
    this->act = act;
}

string Idea::toString()
{
	return description + ";" + status + ";" + creator + ";" + act + "\n";
}

