#define _CRTDBG_MAP_ALLOC
#include "UserInterface.h"
#include <stdlib.h>
#include "Tests.h"
#include <windows.h>
#include <crtdbg.h>


int main() {
	//runTests();
	ProfilesVector *profilesRepository = createRepository(1);
	RepositoryStack *stack = createUndoRedoStack(1);
	runConsole(profilesRepository,stack);
	destroyRepository(profilesRepository);
	destroyStack(stack);
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}