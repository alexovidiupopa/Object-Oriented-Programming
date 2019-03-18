#include <crtdbg.h>
#include <stdlib.h>
#include <stdio.h>
#include "UserInterface.h"

int main()
{
	DynamicArray* profileRepository = createArray(1, &destroyProfile, &copyProfile);
	DynamicArray* repositoryStack = createArray(1, &destroyRepository, &copyRepository);
	runConsole(profileRepository,repositoryStack);
	destroyArray(profileRepository);
	destroyArray(repositoryStack);
	_CrtDumpMemoryLeaks();
	return 0;
}