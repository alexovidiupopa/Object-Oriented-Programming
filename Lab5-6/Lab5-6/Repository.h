#pragma once
#include "DynamicVector.h"

class Repository {

private:
	DynamicVector tapes;

	int searchForTape(char title[]);
public:

	Repository() {}
	
	bool addTapeToRepository(Tape tapeToAdd);

	bool removeTapeFromRepo(char title[]);

	bool updateTapeInRepo(Tape tapeToUpdate);

	DynamicVector getAllTapes();

};

