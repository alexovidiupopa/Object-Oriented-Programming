#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <stdio.h>
#include "UserInterface.h"
#include "Tests.h"
int main()
{
	runTests();
	DynamicArray* profileRepository = createArray(1, &destroyProfile, &copyProfile);
	DynamicArray* repositoryStack = createArray(1, &destroyArray, &copyArray);
	runConsole(profileRepository,repositoryStack);
	destroyArray(profileRepository);
	destroyArray(repositoryStack);
	_CrtDumpMemoryLeaks();
	return 0;
}