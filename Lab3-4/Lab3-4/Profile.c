#include "Profile.h"
#include <string.h>

Profile* createProfile(char profileIdNumber[], char placeOfBirth[], char psychologicalProfile[], int yearsOfRecordedService)
{
	///the function creates and returns a new profile with the given parameters.
	Profile* newProfile = (Profile*)malloc(sizeof(Profile));
	newProfile->profileIdNumber = (char*)malloc(sizeof(char)*(strlen(profileIdNumber) + 1));
	strcpy(newProfile->profileIdNumber, profileIdNumber);
	newProfile->placeOfBirth = (char*)malloc(sizeof(char)*(strlen(placeOfBirth) + 1));
	strcpy(newProfile->placeOfBirth, placeOfBirth);
	newProfile->psychologicalProfile = (char*)malloc(sizeof(char)*(strlen(psychologicalProfile) + 1));
	strcpy(newProfile->psychologicalProfile, psychologicalProfile);
	newProfile->yearsOfRecordedService = yearsOfRecordedService;
	return newProfile;
}

void destroyProfile(Profile *profileToDestroy)
{
	if (profileToDestroy == NULL)
		return;
	
	free(profileToDestroy->profileIdNumber);
	free(profileToDestroy->placeOfBirth);
	free(profileToDestroy->psychologicalProfile);

	free(profileToDestroy);
}
