#pragma once
#include <vector>
#include "Tape.h"
#include "Exceptions.h"
class Repository {

private:
	std::vector<Tape> tapes;
	std::vector<Tape> playlist;
	int searchForTape(std::string title);
public:

	Repository() {}
	
	void addTapeToRepository(Tape tapeToAdd);

	void removeTapeFromRepo(std::string title);

	void updateTapeInRepo(Tape tapeToUpdate);

	std::vector<Tape> getAllTapes();

	std::vector<Tape> getPlaylist();

	void saveTape(std::string givenTitle);

};

