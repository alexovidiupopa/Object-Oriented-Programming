#pragma once
#include "DynamicVector.h"
#include "Tape.h"
class Repository {

private:
	DynamicVector<Tape> tapes;
	DynamicVector<Tape> playlist;
	int searchForTape(char title[]);
public:

	Repository() {}
	
	bool addTapeToRepository(Tape tapeToAdd);

	bool removeTapeFromRepo(char title[]);

	bool updateTapeInRepo(Tape tapeToUpdate);

	DynamicVector<Tape> getAllTapes();

	DynamicVector<Tape> getPlaylist();

	bool saveTape(char givenTitle[]);

};

