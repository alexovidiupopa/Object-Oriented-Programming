#pragma once
#include "Repository.h"
#include "Tape.h"
class RedoOperation
{
public:
	RedoOperation();
	virtual void executeRedo() = 0;
	virtual ~RedoOperation();
};

