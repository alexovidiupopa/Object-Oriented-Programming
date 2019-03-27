#pragma once
#include "Tape.h"

class Repository {

private:
	int length, capacity;
	Tape* tapes;

	void resize();

	int searchForTape(Tape tapeToSearchFor);
public: 

	Repository();
	
	bool addTapeToRepository(Tape tapeToAdd);

	bool removeTapeFromRepo(Tape tapeToRemove);

	bool updateTapeInRepo(Tape tapeToUpdate);

	void getAllTapes(char tapes[]);

	Repository* copyRepository();

	~Repository();
};

