#pragma once
#include "UndoOperation.h"
#include "Tape.h"
#include "Repository.h"
class UndoDelete :
	public UndoOperation
{
private:
	Repository& tapesRepository;
	Tape tape;
public:
	UndoDelete(Repository& tapesRepo, Tape t) :tapesRepository{ tapesRepo }, tape{ t }, UndoOperation() {};
	void executeUndo()override;
	virtual ~UndoDelete();
};

