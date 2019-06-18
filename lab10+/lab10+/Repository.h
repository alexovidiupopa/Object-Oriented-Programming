#pragma once
#include <vector>
#include "Tape.h"
#include "Exceptions.h"
class Repository {

private:
	std::vector<Tape> tapes;
	int searchForTape(std::string title);
public:

	Repository() {}

	void addTapeToRepository(Tape tapeToAdd);

	void removeTapeFromRepo(std::string title);

	void updateTapeInRepo(Tape tapeToUpdate);

	std::vector<Tape> getAllTapes();

	Tape getTapeWithTitle(std::string title) { return this->tapes[searchForTape(title)]; }
	virtual void loadRepository() {};
	virtual void saveRepository() {};
	virtual void setPath(std::string path) {};

};

