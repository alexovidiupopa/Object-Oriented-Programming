#include "Controller.h"
#include "Tests.h"
#include "assert.h"

void testProfile()
{
	char testId[] = "1";
	char testPlaceOfBirth[] = "New York";
	char testPsychologicalProfile[] = "abcd";
	int yearsOfService = 3;
	Profile testProfile;
	strcpy(testProfile.profileIdNumber, testId);
	strcpy(testProfile.placeOfBirth, testPlaceOfBirth);
	strcpy(testProfile.psychologicalProfile, testPsychologicalProfile);
	testProfile.yearsOfRecordedService = yearsOfService;
	assert(strcmp(testProfile.profileIdNumber,"1") == 0);
	assert(testProfile.yearsOfRecordedService == 3);
	testProfile.yearsOfRecordedService = 4;
	assert(testProfile.yearsOfRecordedService == 4);
}

void testAdd()
{
	
}
void runTests()
{
	testProfile();
}