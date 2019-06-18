#include "UndoDelete.h"


void UndoDelete::executeUndo()
{
	this->tapesRepository.addTapeToRepository(tape);
}

UndoDelete::~UndoDelete()
{
}
