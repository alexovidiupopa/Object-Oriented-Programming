/*#pragma once
#include "Profile.h"
#include "Repository.h"

typedef struct {
	Profile* profile;
	char *operationType;
}Operation;

typedef struct {
	Operation* operations[100];
	int length;
	int indexForAdd;
}Operations;

int undo(Operations undoStack, Operations redoStack, ProfilesVector *profilesRepository);
int redo(Operations undoStack, Operations redoStack, ProfilesVector *profilesRepository);
*/