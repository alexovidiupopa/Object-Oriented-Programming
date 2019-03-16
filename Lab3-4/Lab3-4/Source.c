#include <crtdbg.h>
#include "UserInterface.h"
#include <stdlib.h>
#include "Tests.h"
#define _CRTDBG_MAP_ALLOC

int main() {
	runTests();
	ProfilesVector *profilesRepository = (ProfilesVector*)malloc(sizeof(ProfilesVector));
	*profilesRepository = createRepository();
	runConsole(profilesRepository);
	destroyRepository(profilesRepository);
	_CrtDumpMemoryLeaks();
	return 0;
}