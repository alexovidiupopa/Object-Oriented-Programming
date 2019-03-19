#include "Repository.h"
#pragma once

int searchProfileInRepositoryAfterId(char profileIdNumber[], DynamicArray * profilesRepository)
{
	for (int i = 0; i < profilesRepository->size; i++)
		if (strcmp(getID(profilesRepository->elements[i]), profileIdNumber) == 0)
			return i;
	return -1;
}

int addProfileToRepository(Profile* profileToAdd, DynamicArray * profilesRepository)
{
	profilesRepository->elements[profilesRepository->size++] = copyProfile(profileToAdd);
	return 1;
}

int deleteProfileFromRepository(char profileIdNumber[], DynamicArray * profilesRepository)
{
	int index = searchProfileInRepositoryAfterId(profileIdNumber, profilesRepository);
	if (index == -1) {
		return -1;
	}
	profilesRepository->size--;
	int i;
	for (i = index; i < profilesRepository->size; i++) {
		profilesRepository->elements[i] = profilesRepository->elements[i + 1];
	}
	destroyProfile(profilesRepository->elements[profilesRepository->size]);
	return 1;
}

void updateProfileInRepository(Profile *profileToUpdate, DynamicArray * profilesRepository,int index)
{
	destroyProfile(profilesRepository->elements[index]);
	profilesRepository->elements[index] = copyProfile(profileToUpdate);
}

void destroyRepository(DynamicArray * profileRepository)
{
	for (int i = 0; i < profileRepository->size; i++)
		profileRepository->destroyFct(profileRepository->elements[i]);
	free(profileRepository->elements);
	free(profileRepository);
}

ProfilesRepository *copyRepository(ProfilesRepository * repositoryToCopy)
{
	ProfilesRepository* newA = (ProfilesRepository*)malloc(sizeof(ProfilesRepository));
	newA->capacity = repositoryToCopy->capacity;
	newA->size = repositoryToCopy->size;
	newA->profiles = (Profile*)malloc(sizeof(Profile)*repositoryToCopy->capacity);
	
	for (int i = 0; i < repositoryToCopy->size; i++)
		newA->profiles[i] = repositoryToCopy->profiles[i];

	return newA;
}

DynamicArray* profilesWithLessThanAGivenValue(DynamicArray *dynamicArray, int givenValue)
{
	DynamicArray* temporaryArray = createArray(dynamicArray->capacity, dynamicArray->destroyFct, dynamicArray->copyFct);
	for (int i = 0; i < dynamicArray->size; i++)
		if (getYearsOfRecordedService(dynamicArray->elements[i]) < givenValue)
			addToArray(temporaryArray, dynamicArray->elements[i]);
	return temporaryArray;
}