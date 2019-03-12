
#include "UserInterface.h"
#include <stdlib.h>

int main() {
	ProfilesVector *profilesRepository = (ProfilesVector*)malloc(sizeof(ProfilesVector));
	*profilesRepository = createRepository();
	runConsole(profilesRepository);
	return 0;
}