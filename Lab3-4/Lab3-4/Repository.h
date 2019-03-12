#pragma once

#include "Profile.h"

typedef struct {
	Profile profiles[30];
	int length; 
}ProfilesVector;

ProfilesVector createRepository();

int searchProfileInRepositoryAfterId(char profileIdNumber[], ProfilesVector *profilesRepository);

int addProfileToRepository(Profile profileToAdd, ProfilesVector *profilesRepository);

int deleteProfileFromRepository(char profileIdNumber[], ProfilesVector *profilesRepository);

int updateProfileInRepository(Profile profileToUpdate, ProfilesVector *profilesRepository);
