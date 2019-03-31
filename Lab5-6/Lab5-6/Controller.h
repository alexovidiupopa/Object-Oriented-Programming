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

	void listTapes(char tapesToPrint[]);

	void listTapesFilmedAtLessThanCount(char tapesToPrint[], char givenFilmedAt[], int givenAccessCount);

	void listPlaylist(char playlistToBeListed[]);

	bool saveToPlaylist(char givenTitle[]);

	void initializeIndex();

	Tape nextInPlaylist();
};