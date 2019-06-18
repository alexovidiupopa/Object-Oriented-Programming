#include "RedoAdd.h"

void RedoAdd::executeRedo()
{
	this->tapesRepo.addTapeToRepository(tape);
}

RedoAdd::~RedoAdd()
{
}
