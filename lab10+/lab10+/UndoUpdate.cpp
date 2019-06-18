#include "UndoUpdate.h"


void UndoUpdate::executeUndo()
{
	this->tapesRepository.updateTapeInRepo(tape);
}

UndoUpdate::~UndoUpdate()
{
}
