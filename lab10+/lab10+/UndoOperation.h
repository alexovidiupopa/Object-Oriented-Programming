#pragma once
class UndoOperation
{
public:
	UndoOperation();
	virtual void executeUndo()=0;
	virtual ~UndoOperation();
};

