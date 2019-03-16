#include "Controller.h"
#include "Profile.h"

int addProfile(ProfilesVector * profilesRepository, char profileIdNumber[], char placeOfBirth[], char psychologialProfile[], int yearsOfRecordedService)
{
	///the controller function creates a new profile with the given parameters and then returns the result of adding the profile to the repository
	Profile profileToAdd = createProfile(profileIdNumber, placeOfBirth, psychologialProfile, yearsOfRecordedService);
	return addProfileToRepository(profileToAdd, profilesRepository);
}

int deleteProfile(ProfilesVector * profilesRepository, char profileIdNumber[])
{
	///the function returns the result of deleting the profile with the profile id number <profileIdNumber> from the repository
	return deleteProfileFromRepository(profileIdNumber, profilesRepository);
}

int updateProfile(ProfilesVector * profilesRepository, char profileIdNumber[], char newPlaceOfBirth[], char newPsychologialProfile[], int newYearsOfRecordedService)
{
	///the controller function creates a new profile with the given parameters and then returns the result of updating the profile in the repository
	Profile profileToUpdate = createProfile(profileIdNumber, newPlaceOfBirth, newPsychologialProfile, newYearsOfRecordedService);
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

const char* listProfilesByYears(ProfilesVector *profilesRepository, int yearsToFilter)
{
	char s[] = "asd";
	return s;
}