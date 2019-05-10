#include "UndoRemoveOperation.h"



void UndoRemoveOperation::executeUndo()
{
	this->paintingsRepo.addPainting(this->painting);
	this->specialPaintingsRepo.removePainting(this->painting);
}

UndoRemoveOperation::~UndoRemoveOperation()
{
}
