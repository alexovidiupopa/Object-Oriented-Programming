#include "RedoUpdate.h"


void RedoUpdate::executeRedo()
{
	this->tapesRepo.updateTapeInRepo(this->tape);
}

RedoUpdate::~RedoUpdate()
{
}
