#pragma once
#include "UndoOperation.h"
#include "Repository.h"
class UndoAddOperation :
	public UndoOperation
{
private:
	Repository &paintingsRepo;
	Painting painting;
	
public:
	UndoAddOperation(Repository& paintingsRepo,Painting p) :paintingsRepo{ paintingsRepo }, UndoOperation(), painting{p}{};
	void executeUndo()override;
	~UndoAddOperation();
};

