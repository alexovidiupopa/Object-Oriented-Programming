#include "Controller.h"


int addProfile(ProfilesVector * profilesRepository, char *profileIdNumber, char *placeOfBirth, char *psychologialProfile, int yearsOfRecordedService, RepositoryStack *stack)
{
	///the controller function creates a new profile with the given parameters and then returns the result of adding the profile to the repository
	Profile profileToAdd = createProfile(profileIdNumber, placeOfBirth, psychologialProfile, yearsOfRecordedService);
	stack->index++;
	addToStack(stack, profilesRepository);
	return addProfileToRepository(profileToAdd, profilesRepository);
}

int deleteProfile(ProfilesVector * profilesRepository, char profileIdNumber[],RepositoryStack *stack)
{
	///the function returns the result of deleting the profile with the profile id number <profileIdNumber> from the repository
	stack->index++;
	addToStack(stack, profilesRepository);
	return deleteProfileFromRepository(profileIdNumber, profilesRepository);
}

int updateProfile(ProfilesVector * profilesRepository, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService,RepositoryStack *stack)
{
	///the controller function creates a new profile with the given parameters and then returns the result of updating the profile in the repository
	Profile profileToUpdate = createProfile(profileIdNumber, newPlaceOfBirth, newPsychologialProfile, newYearsOfRecordedService);
	stack->index++;
	addToStack(stack, profilesRepository);
	return updateProfileInRepository(profileToUpdate, profilesRepository);
}


const char* listProfiles(ProfilesVector * profilesRepository)
{
	///the function creates and returns a string representing all the profiles in the repository.
	char profilesToPrint[201];
	int i;
	profilesToPrint[0] = 0;
	for (i = 0; i < profilesRepository->length; i++) {
		char auxiliary[11];
		strcat(profilesToPrint, profilesRepository->profiles[i].profileIdNumber);
		strcat(profilesToPrint, " ");
		strcat(profilesToPrint, profilesRepository->profiles[i].placeOfBirth);
		strcat(profilesToPrint, " ");
		strcat(profilesToPrint, profilesRepository->profiles[i].psychologicalProfile);
		strcat(profilesToPrint, " ");
		itoa(profilesRepository->profiles[i].yearsOfRecordedService, auxiliary, 10);
		strcat(profilesToPrint, auxiliary);
		strcat(profilesToPrint, "\n");
	}
	return profilesToPrint;
}

const char * listProfilesByPsychologicalProfile(ProfilesVector * profilesRepository, char psychologicalProfile[])
{
	///the function creates and returns a string representing all the profiles which have the psychological profile like the <psychologicalProfile> parameter from the repository.
	char profilesToPrint[201];
	int i; 
	profilesToPrint[0] = 0;
	for (i = 0; i < profilesRepository->length; i++) {
		if (strcmp(profilesRepository->profiles[i].psychologicalProfile, psychologicalProfile) == 0) {
			char auxiliary[11];
			strcat(profilesToPrint, profilesRepository->profiles[i].profileIdNumber);
			strcat(profilesToPrint, " ");
			strcat(profilesToPrint, profilesRepository->profiles[i].placeOfBirth);
			strcat(profilesToPrint, " ");
			strcat(profilesToPrint, profilesRepository->profiles[i].psychologicalProfile);
			strcat(profilesToPrint, " ");
			itoa(profilesRepository->profiles[i].yearsOfRecordedService, auxiliary, 10);
			strcat(profilesToPrint, auxiliary);
			strcat(profilesToPrint, "\n");
		}
	}
	return profilesToPrint;
}

void sortProfiles(ProfilesVector *profilesToSort)
{
	for (int i = 0; i < profilesToSort->length - 1; i++) {
		for (int j = i + 1; j < profilesToSort->length; j++) {
			if (strcmp(profilesToSort->profiles[i].placeOfBirth, profilesToSort->profiles[j].placeOfBirth) > 0) {
				Profile auxiliary;
				auxiliary = profilesToSort->profiles[i];
				profilesToSort->profiles[i] = profilesToSort->profiles[j];
				profilesToSort->profiles[j] = auxiliary;
			}
		}
	}
}
int undo(ProfilesVector* profilesRepository, RepositoryStack * stack)
{
	if (stack->index-1 == -1)
		return -1;
	stack->index--;
	replaceRepository(profilesRepository, stack->repositories[stack->index]);
	return 1;
}

int redo(ProfilesVector* profilesRepository, RepositoryStack * stack)
{
	
	if (stack->index == stack->length)
		return -1;
	stack->index++;
	replaceRepository(profilesRepository, stack->repositories[stack->index]);
	return 1;
}

const char* listProfilesByYears(ProfilesVector *profilesRepository, int yearsToFilter)
{
	ProfilesVector *profilesToSort = profilesWithLessThanAGivenValue(profilesRepository, yearsToFilter);
	sortProfiles(profilesToSort);
	char profilesToPrint[201];
	int i;
	profilesToPrint[0] = 0;
	for (i = 0; i < profilesToSort->length; i++) {
		char auxiliary[11];
		strcat(profilesToPrint, profilesToSort->profiles[i].profileIdNumber);
		strcat(profilesToPrint, " ");
		strcat(profilesToPrint, profilesToSort->profiles[i].placeOfBirth);
		strcat(profilesToPrint, " ");
		strcat(profilesToPrint, profilesToSort->profiles[i].psychologicalProfile);
		strcat(profilesToPrint, " ");
		itoa(profilesToSort->profiles[i].yearsOfRecordedService, auxiliary, 10);
		strcat(profilesToPrint, auxiliary);
		strcat(profilesToPrint, "\n");
	}
	return profilesToPrint;
}

