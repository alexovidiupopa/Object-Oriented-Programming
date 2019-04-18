#pragma once
#include "FileRepository.h"

class Controller {

private:

	FileRepository repository;
	int indexForPlaylistIterating;
public:

	Controller(FileRepository& repository) : repository{ repository } {}

	void addTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount);

	void removeTape(std::string givenTitle);

	void updateTape(std::string givenTitle, std::string givenFilmedAt, std::string givenCreationDate, std::string givenFootagePreview, int givenAccessCount);

	std::vector<Tape> listTapes();

	std::vector<Tape> listTapesFilmedAtLessThanCount(std::string givenFilmedAt, int givenAccessCount);

	std::vector<Tape> listPlaylist();

	void saveToPlaylist(std::string givenTitle);

	void initializeIndex();

	Tape nextInPlaylist();

	void setRepository(std::string path);

	void saveRepository();
};