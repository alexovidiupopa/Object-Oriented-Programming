#pragma once
#include <vector>
#include "Tape.h"
#include "Exceptions.h"
class Repository {

private:
	std::vector<Tape> tapes;
	std::vector<Tape> playlist;
	int searchForTape(char title[]);
public:

	Repository() {}
	
	bool addTapeToRepository(Tape tapeToAdd);

	bool removeTapeFromRepo(char title[]);

	bool updateTapeInRepo(Tape tapeToUpdate);

	std::vector<Tape> getAllTapes();

	std::vector<Tape> getPlaylist();

	bool saveTape(char givenTitle[]);

};

