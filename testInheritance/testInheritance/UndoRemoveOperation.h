#pragma once
#include "UndoOperation.h"
#include "Repository.h"
class UndoRemoveOperation :
	public UndoOperation
{
private: 
	Repository &paintingsRepo;
	Repository &specialPaintingsRepo;
	Painting painting;
public:
	UndoRemoveOperation(Repository &paintingsRepo, Repository &specialPaintingsRepo, Painting painting) :paintingsRepo{ paintingsRepo }, specialPaintingsRepo{ specialPaintingsRepo }, painting{ painting }{};
	void executeUndo() override;
	~UndoRemoveOperation();
};

