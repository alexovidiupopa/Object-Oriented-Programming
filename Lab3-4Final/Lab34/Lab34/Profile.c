#include "Profile.h"

Profile * createProfile(char * profileIdNumber, char * placeOfBirth, char * psychologicalProfile, int yearsOfRecordedService)
{
	Profile *profile = (Profile*)malloc(sizeof(Profile));
	profile->profileIdNumber = (char*)malloc(sizeof(char)*(strlen(profileIdNumber) + 1));
	strcpy(profile->profileIdNumber, profileIdNumber);
	profile->placeOfBirth = (char*)malloc(sizeof(char)*(strlen(placeOfBirth) + 1));
	strcpy(profile->placeOfBirth, placeOfBirth);
	profile->psychologicalProfile = (char*)malloc(sizeof(char)*(strlen(psychologicalProfile) + 1));
	strcpy(profile->psychologicalProfile, psychologicalProfile);
	profile->yearsOfRecordedService = yearsOfRecordedService;
	return profile;
}

char * getID(Profile * profile)
{
	return profile->profileIdNumber;
}

char * getPlaceOfBirth(Profile * profile)
{
	return profile->placeOfBirth;
}

char * getPsychologicalProfile(Profile * profile)
{
	return profile->psychologicalProfile;
}

int getYearsOfRecordedService(Profile * profile)
{
	return profile->yearsOfRecordedService;
}

void destroyProfile(Profile* profileToDestroy)
{
	if (profileToDestroy == NULL)
		return;
	free(profileToDestroy->profileIdNumber);
	free(profileToDestroy->placeOfBirth);
	free(profileToDestroy->psychologicalProfile);
	//profileToDestroy->profileIdNumber = NULL;
	//profileToDestroy->placeOfBirth = NULL;
	//profileToDestroy->psychologicalProfile = NULL;
	free(profileToDestroy);
	
	//profileToDestroy = NULL;
}

void toString(Profile* printProfile)
{
	printf("%s %s %s %d\n", printProfile->profileIdNumber, printProfile->placeOfBirth, printProfile->psychologicalProfile, printProfile->yearsOfRecordedService);
}

Profile * copyProfile(Profile * profileToCopy)
{
	Profile* copy = (Profile*)malloc(sizeof(Profile));
	copy->profileIdNumber = (char*)malloc(sizeof(char)*(strlen(profileToCopy->profileIdNumber) + 1));
	strcpy(copy->profileIdNumber, profileToCopy->profileIdNumber);
	copy->placeOfBirth = (char*)malloc(sizeof(char)*(strlen(profileToCopy->placeOfBirth) + 1));
	strcpy(copy->placeOfBirth, profileToCopy->placeOfBirth);
	copy->psychologicalProfile = (char*)malloc(sizeof(char)*(strlen(profileToCopy->psychologicalProfile) + 1));
	strcpy(copy->psychologicalProfile, profileToCopy->psychologicalProfile);
	copy->yearsOfRecordedService = profileToCopy->yearsOfRecordedService;

	return copy;
}
