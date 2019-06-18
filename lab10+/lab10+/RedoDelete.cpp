#include "RedoDelete.h"

void RedoDelete::executeRedo()
{
	this->tapesRepo.removeTapeFromRepo(this->tape.getTitle());
}

RedoDelete::~RedoDelete()
{
}
