#pragma once
#include "Repository.h"

class Controller {

private:

	Repository repository;
	int indexForPlaylistIterating;
public:

	Controller(Repository& repository) : repository{ repository } {}

	bool addTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount);

	bool removeTape(char givenTitle[]);

	bool updateTape(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount);

	std::vector<Tape> listTapes();

	std::vector<Tape> listTapesFilmedAtLessThanCount(char givenFilmedAt[], int givenAccessCount);

	std::vector<Tape> listPlaylist();

	bool saveToPlaylist(char givenTitle[]);

	void initializeIndex();

	Tape nextInPlaylist();
};