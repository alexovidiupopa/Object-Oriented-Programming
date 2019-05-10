#pragma once
#include "Playlist.h"
class FilePlaylist :
	public Playlist
{

protected: 
	std::string file;

public:
	FilePlaylist() : Playlist{}, file{ "" } {};
	virtual ~FilePlaylist() {}
	void setFileName(std::string fileName);
	virtual void writeToFile() = 0;
	virtual void displayPlaylist() const = 0;
	virtual std::vector<Tape> printPlaylistOnScreen() const = 0;
};

