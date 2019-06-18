#pragma once
#include "UndoOperation.h"
#include "Tape.h"
#include "Repository.h"
class UndoAdd :
	public UndoOperation
{
private:
	Repository& tapesRepository;
	Tape tape;
public:
	UndoAdd(Repository& tapesRepo, Tape t) :tapesRepository{ tapesRepo }, tape{ t }, UndoOperation() {};
	void executeUndo()override;
	virtual ~UndoAdd();
};

