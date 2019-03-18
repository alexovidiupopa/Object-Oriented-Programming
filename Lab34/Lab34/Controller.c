#pragma once
#include "Controller.h"
#include <stdio.h>

int addProfile(DynamicArray * DynamicArray, char *profileIdNumber, char *placeOfBirth, char *psychologialProfile, int yearsOfRecordedService)
{
	///the controller function creates a new profile with the given parameters and then returns the result of adding the profile to the repository
	Profile *profileToAdd = createProfile(profileIdNumber, placeOfBirth, psychologialProfile, yearsOfRecordedService);
	//stack->index++;
	//addToStack(stack, DynamicArray);
	return addProfileToRepository(profileToAdd, DynamicArray);
}

int deleteProfile(DynamicArray * DynamicArray, char profileIdNumber[])
{
	///the function returns the result of deleting the profile with the profile id number <profileIdNumber> from the repository
	//stack->index++;
	//addToStack(stack, DynamicArray);
	return deleteProfileFromRepository(profileIdNumber, DynamicArray);
}

int updateProfile(DynamicArray * DynamicArray, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService)
{
	///the controller function creates a new profile with the given parameters and then returns the result of updating the profile in the repository
	Profile* profileToUpdate = createProfile(profileIdNumber, newPlaceOfBirth, newPsychologialProfile, newYearsOfRecordedService);
	//stack->index++;
	//addToStack(stack, DynamicArray);
	return updateProfileInRepository(profileToUpdate, DynamicArray);
}


void listProfiles(DynamicArray * DynamicArray)
{
	///the function creates and returns a string representing all the elements in the repository.
	char profilesToPrint[201];
	int i;
	profilesToPrint[0] = 0;
	for (i = 0; i < DynamicArray->size; i++) {
		toString(DynamicArray->elements[i]);
	}
	//return profilesToPrint;
}

void listProfilesByPsychologicalProfile(DynamicArray * DynamicArray, char psychologicalProfile[])
{
	///the function creates and returns a string representing all the elements which have the psychological profile like the <psychologicalProfile> parameter from the repository.
	char profilesToPrint[201];
	int i;
	profilesToPrint[0] = 0;
	for (i = 0; i < DynamicArray->size; i++) {
		if (strcmp(getPsychologicalProfile(DynamicArray->elements[i]), psychologicalProfile) == 0) {
			toString(DynamicArray->elements[i]);
		}
	}
	
}

void sortProfiles(DynamicArray *profilesToSort)
{
	for (int i = 0; i < profilesToSort->size - 1; i++) {
		for (int j = i + 1; j < profilesToSort->size; j++) {
			if (strcmp(getPlaceOfBirth(profilesToSort->elements[i]), getPlaceOfBirth(profilesToSort->elements[j])) < 0) {
				Profile* auxiliary;
				auxiliary = profilesToSort->elements[i];
				profilesToSort->elements[i] = profilesToSort->elements[j];
				profilesToSort->elements[j] = auxiliary;
			}
		}
	}
}
void listProfilesWithLessThanAGivenValue(DynamicArray * dynamicArray, int givenValue)
{
	DynamicArray* profilesToSort = profilesWithLessThanAGivenValue(dynamicArray, givenValue);
	sortProfiles(profilesToSort);
	for (int i = 0; i < profilesToSort->size; i++)
		toString(profilesToSort->elements[i]);
}

void addToStack(DynamicArray *repositoryStack, ProfilesRepository * tempArray)
{
	//repositoryStack->elements[repositoryStack->size++] = tempArray->copyFct(tempArray);
	repositoryStack->elements[repositoryStack->size++] = tempArray;
}
