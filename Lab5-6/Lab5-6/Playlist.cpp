#include "Playlist.h"

void Playlist::saveTape(const Tape & tape)
{
	this->tapes.push_back(tape);
}
