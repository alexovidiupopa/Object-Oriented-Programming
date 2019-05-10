#pragma once
#include "Painting.h"
class UndoOperation
{

public:
	UndoOperation();
	virtual void executeUndo() = 0;
	virtual ~UndoOperation();
};

