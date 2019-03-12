#include "Profile.h"
#include <string.h>

Profile createProfile(char profileIdNumber[], char placeOfBirth[], char psychologicalProfile[], int yearsOfRecordedService)
{
	///the function creates and returns a new profile with the given parameters.
	Profile newProfile;
	strcpy(newProfile.profileIdNumber, profileIdNumber);
	strcpy(newProfile.placeOfBirth, placeOfBirth);
	strcpy(newProfile.psychologicalProfile, psychologicalProfile);
	newProfile.yearsOfRecordedService = yearsOfRecordedService;
	return newProfile;
}
