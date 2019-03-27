#pragma once
#include "Tape.h"

class Repository {

private:
	int length, capacity;
	Tape* tapes;

	void resize();

	int searchForTape(char title[]);
public: 

	Repository();
	
	bool addTapeToRepository(Tape tapeToAdd);

	bool removeTapeFromRepo(char title[]);

	bool updateTapeInRepo(Tape tapeToUpdate);

	void getAllTapes(char tapes[]);

	Repository* copyRepository();

	~Repository();
};

