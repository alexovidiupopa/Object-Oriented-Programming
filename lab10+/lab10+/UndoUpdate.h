#pragma once
#include "UndoOperation.h"
#include <Tape.h>
#include <Repository.h>
class UndoUpdate :
	public UndoOperation
{
private: 
	Repository& tapesRepository;
	Tape tape;
public:
	UndoUpdate(Repository& tapesRepo, Tape t) :tapesRepository{ tapesRepo }, tape{ t }, UndoOperation() {};
	void executeUndo()override;
	~UndoUpdate();
};

