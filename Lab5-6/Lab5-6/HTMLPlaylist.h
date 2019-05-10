#pragma once
#include "FilePlaylist.h"
class HTMLPlaylist :
	public FilePlaylist
{
public:

	void writeToFile() override;

	void displayPlaylist() const override;

	std::vector<Tape> printPlaylistOnScreen() const override;
};

