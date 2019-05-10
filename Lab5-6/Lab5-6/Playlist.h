#pragma once
#include <vector>
#include "Tape.h"

class Playlist {
protected:

	std::vector <Tape> tapes;
	

public:

	Playlist() {};

	void saveTape(const Tape& tape);

	virtual ~Playlist() {}
};