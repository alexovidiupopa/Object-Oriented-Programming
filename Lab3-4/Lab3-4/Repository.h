#pragma once

#include "Profile.h"

typedef struct {
	Profile* profiles;
	int length,capacity; 
}ProfilesVector;

ProfilesVector* createRepository(int capacity);

int searchProfileInRepositoryAfterId(char profileIdNumber[], ProfilesVector *profilesRepository);

int addProfileToRepository(Profile profileToAdd, ProfilesVector *profilesRepository);

int deleteProfileFromRepository(char profileIdNumber[], ProfilesVector *profilesRepository);

int updateProfileInRepository(Profile profileToUpdate, ProfilesVector *profilesRepository);

void destroyRepository(ProfilesVector *profileRepository);
void resize(ProfilesVector *profilesRepository);