#pragma once
#include <stdlib.h>
typedef struct {
	char *profileIdNumber;
	char *placeOfBirth;
	char *psychologicalProfile;
	int yearsOfRecordedService;
}Profile;

Profile createProfile(char *profileIdNumber, char *placeOfBirth, char *psychologicalProfile, int yearsOfRecordedService);

void destroyProfile(Profile profileToDestroy);

Profile copyProfile(Profile* profileToCopy);