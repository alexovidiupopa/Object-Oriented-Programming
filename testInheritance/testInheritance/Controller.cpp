#include "Controller.h"
#include "UndoAddOperation.h"
#include "UndoRemoveOperation.h"
Controller::Controller()
{
}

void Controller::addPainting(std::string artist, std::string title, int year)
{
	this->repoAll.addPainting(Painting{ title,artist,year });
	UndoOperation* undoOperation = new UndoAddOperation(this->repoAll, Painting{ title, artist, year });
	this->operations.push_back(undoOperation);
}

void Controller::removePainting(std::string artist, std::string title, int year)
{
	this->repoAll.removePainting(Painting{ title,artist,year });
	this->repoSpecialStorage.addPainting(Painting{ title,artist,year });
	UndoOperation* undoOperation = new UndoRemoveOperation(this->repoAll,this->repoSpecialStorage, Painting{ title, artist, year });
	this->operations.push_back(undoOperation);
}

std::vector<Painting> Controller::getAll()
{
	return this->repoAll.getAll();
}

std::vector<Painting> Controller::getSpecialStorage()
{
	return this->repoSpecialStorage.getAll();
}

void Controller::undo()
{
	this->operations[this->operations.size()-1]->executeUndo();
	this->operations.pop_back();
}


Controller::~Controller()
{
}
