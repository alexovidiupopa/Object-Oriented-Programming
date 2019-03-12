#pragma once

#include "Repository.h"

int addProfile(ProfilesVector *profilesRepository, char profileIdNumber[], char placeOfBirth[], char psychologialProfile[], int yearsOfRecordedService);

int deleteProfile(ProfilesVector *profilesRepository, char profileIdNumber[]);

int updateProfile(ProfilesVector *profilesRepository, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService);

const char* listProfiles(ProfilesVector *profilesRepository);

const char* listProfilesByPsychologicalProfile(ProfilesVector *profilesRepository, char psychologicalProfile[]);

