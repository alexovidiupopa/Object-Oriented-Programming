#pragma once
#include "Controller.h"
#include <stdio.h>

int addProfile(DynamicArray * profilesRepository, char *profileIdNumber, char *placeOfBirth, char *psychologialProfile, int yearsOfRecordedService)
{
	///the controller function creates a new profile with the given parameters and then returns the result of adding the profile to the repository
	
	if (searchProfileInRepositoryAfterId(profileIdNumber, profilesRepository) != -1)
		return -1;
	Profile *profileToAdd = createProfile(profileIdNumber, placeOfBirth, psychologialProfile, yearsOfRecordedService);
	addToArray(profilesRepository,profileToAdd);
	destroyProfile(profileToAdd);
	return 1;
}

int deleteProfile(DynamicArray * profilesRepository, char profileIdNumber[])
{
	///the function returns the result of deleting the profile with the profile id number <profileIdNumber> from the repository
	return deleteProfileFromRepository(profileIdNumber, profilesRepository);
}

int updateProfile(DynamicArray * profilesRepository, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService)
{
	///the controller function creates a new profile with the given parameters and then returns the result of updating the profile in the repository
	int updateIndex = searchProfileInRepositoryAfterId(profileIdNumber, profilesRepository);
	if (updateIndex == -1)
		return -1;
	Profile* profileToUpdate = createProfile(profileIdNumber, newPlaceOfBirth, newPsychologialProfile, newYearsOfRecordedService);
	updateProfileInRepository(profileToUpdate, profilesRepository,updateIndex);
	destroyProfile(profileToUpdate);
	return 1;
}


void listProfiles(DynamicArray * profilesRepository,char listProfiles[])
{
	///the function creates and returns a string representing all the elements in the repository.
	int i;
	for (i = 0; i < profilesRepository->size; i++) {
		toString(profilesRepository->elements[i], listProfiles);
	}
	
}

void listProfilesByPsychologicalProfile(DynamicArray * profilesRepository, char psychologicalProfile[], char listProfiles[])
{
	///the function creates and returns a string representing all the elements which have the psychological profile like the <psychologicalProfile> parameter from the repository.
	int i;
	for (i = 0; i < profilesRepository->size; i++) {
		if (strcmp(getPsychologicalProfile(profilesRepository->elements[i]), psychologicalProfile) == 0) {
			toString(profilesRepository->elements[i], listProfiles);
		}
	}
}

void sortProfiles(DynamicArray *profilesToSort)
{	
	int i, j;
	for (i = 0; i < profilesToSort->size - 1; i++) {
		for (j = i + 1; j < profilesToSort->size; j++) {
			if (strcmp(getPlaceOfBirth(profilesToSort->elements[i]), getPlaceOfBirth(profilesToSort->elements[j])) < 0) {
				Profile* auxiliary;
				auxiliary = profilesToSort->copyFunction(profilesToSort->elements[i]);
				profilesToSort->destroyFunction(profilesToSort->elements[i]);
				profilesToSort->elements[i] = profilesToSort->copyFunction(profilesToSort->elements[j]);
				profilesToSort->destroyFunction(profilesToSort->elements[j]);
				profilesToSort->elements[j] = profilesToSort->copyFunction(auxiliary);
				profilesToSort->destroyFunction(auxiliary);
			}
		}
	}
}
void listProfilesWithLessThanAGivenValue(DynamicArray * profilesRepository, int givenValue, char listProfiles[])
{
	DynamicArray* profilesToSort = profilesWithLessThanAGivenValue(profilesRepository, givenValue);
	sortProfiles(profilesToSort);
	int i;
	for (i = 0; i < profilesToSort->size; i++)
		toString(profilesToSort->elements[i], listProfiles);
	destroyArray(profilesToSort);
}

