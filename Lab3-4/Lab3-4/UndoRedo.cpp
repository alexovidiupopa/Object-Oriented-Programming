#include "UndoRedo.h"

int undo(Operations undoStack, Operations redoStack,ProfilesVector *profilesRepository)
{
	if (undoStack.length == 0)
		return -1;
	
}

int redo(Operations undoStack, Operations redoStack, ProfilesVector *profilesRepository)
{
	if (redoStack.length == 0)
		return -1;
}
