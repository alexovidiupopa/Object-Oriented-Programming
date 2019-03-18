#pragma once

#include "Repository.h"

int addProfile(ProfilesVector *profilesRepository, char *profileIdNumber, char *placeOfBirth, char *psychologialProfile, int yearsOfRecordedService,RepositoryStack *stack);

int deleteProfile(ProfilesVector *profilesRepository, char profileIdNumber[], RepositoryStack *stack);

int updateProfile(ProfilesVector *profilesRepository, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService, RepositoryStack *stack);

const char* listProfiles(ProfilesVector *profilesRepository);

const char* listProfilesByPsychologicalProfile(ProfilesVector *profilesRepository, char psychologicalProfile[]);

void sortProfiles(ProfilesVector *profilesToSort);

int undo(ProfilesVector *profilesRepository, RepositoryStack *stack);

int redo(ProfilesVector* profilesRepository, RepositoryStack * stack);