#pragma once
#include "FilePlaylist.h"
class FakePlaylist :
	public FilePlaylist
{
public:

	void writeToFile() override {};

	void displayPlaylist() const override {};

	std::vector<Tape> printPlaylistOnScreen() const override { return this->tapes; };
};

