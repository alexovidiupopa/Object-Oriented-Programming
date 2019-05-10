#include "UndoAddOperation.h"



void UndoAddOperation::executeUndo()
{
	this->paintingsRepo.removePainting(this->painting);
}

UndoAddOperation::~UndoAddOperation()
{
}
