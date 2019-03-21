#pragma once

#include "Repository.h"

int addProfile(DynamicArray *DynamicArray, char *profileIdNumber, char *placeOfBirth, char *psychologialProfile, int yearsOfRecordedService);

int deleteProfile(DynamicArray *DynamicArray, char profileIdNumber[]);

int updateProfile(DynamicArray *DynamicArray, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService);

void listProfiles(DynamicArray *DynamicArray, char listProfiles[]);

void listProfilesByPsychologicalProfile(DynamicArray *DynamicArray, char psychologicalProfile[], char listProfiles[]);

void sortProfiles(DynamicArray *profilesToSort);

void listProfilesWithLessThanAGivenValue(DynamicArray *DynamicArray, int givenValue, char listProfiles[]);
