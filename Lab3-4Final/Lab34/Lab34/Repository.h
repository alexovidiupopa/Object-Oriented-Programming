#pragma once
#include "Profile.h"
#include "Vector.h"

typedef struct {
	Profile* profiles;
	int size, capacity;

}ProfilesRepository;

int searchProfileInRepositoryAfterId(char profileIdNumber[], DynamicArray*profilesRepository);

int addProfileToRepository(Profile* profileToAdd, DynamicArray *profilesRepository);

int deleteProfileFromRepository(char profileIdNumber[], DynamicArray *profilesRepository);

void updateProfileInRepository(Profile* profileToUpdate, DynamicArray *profilesRepository,int index);

DynamicArray* profilesWithLessThanAGivenValue(DynamicArray *dynamicArray, int givenValue);