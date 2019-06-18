#include "UndoAdd.h"

void UndoAdd::executeUndo()
{
	this->tapesRepository.removeTapeFromRepo(tape.getTitle());
}

UndoAdd::~UndoAdd()
{
}
