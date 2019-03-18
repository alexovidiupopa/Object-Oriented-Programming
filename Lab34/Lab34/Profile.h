#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct {
	char *profileIdNumber;
	char *placeOfBirth;
	char *psychologicalProfile;
	int yearsOfRecordedService;
}Profile;

Profile* createProfile(char *profileIdNumber, char *placeOfBirth, char *psychologicalProfile, int yearsOfRecordedService);

char *getID(Profile *profile);
char *getPlaceOfBirth(Profile *profile);
char *getPsychologicalProfile(Profile *profile);
int getYearsOfRecordedService(Profile *profile);

void destroyProfile(Profile* profileToDestroy);

Profile* copyProfile(Profile* profileToCopy);
void toString(Profile* printProfile);