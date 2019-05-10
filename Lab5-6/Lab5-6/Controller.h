#pragma once
#include "FileRepository.h"
#include "Validator.h"
#include "FilePlaylist.h"
#include "CSVPlaylist.h"
#include "HTMLPlaylist.h"
class Controller {

private:

	FileRepository repository;
	FilePlaylist* playlist;
	Validator validator;
	int indexForPlaylistIterating;
public:

	Controller(FileRepository& repository, FilePlaylist* playlist, Validator validator) : repository{ repository }, playlist{ playlist }, validator{ validator } {}

	void addTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount);

	void removeTape(std::string givenTitle);

	void updateTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount);

	std::vector<Tape> listTapes();

	std::vector<Tape> listTapesFilmedAtLessThanCount(std::string givenFilmedAt, int givenAccessCount);

	std::vector<Tape> listPlaylist();

	void saveToPlaylist(std::string givenTitle);

	void initializeIndex();

	Tape nextInPlaylist();

	void saveRepository();

	void openPlaylist();
};