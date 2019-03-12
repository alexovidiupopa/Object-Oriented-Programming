#include "Repository.h"
#include <string.h>

ProfilesVector createRepository()
{
	ProfilesVector profilesRepository;
	profilesRepository.length = 0;
	return profilesRepository;
}

int searchProfileInRepositoryAfterId(char profileIdNumber[], ProfilesVector *profilesRepository)
{
	///searches for the profile with the profileIdNumber in the repository. if it exists, it returns its position. if not, it returns -1.
	int i;
	for (i = 0; i < profilesRepository->length; i++) 
		if (strcmp(profilesRepository->profiles[i].profileIdNumber, profileIdNumber) == 0)
			return i;
	return -1;
}

int addProfileToRepository(Profile profileToAdd, ProfilesVector *profilesRepository)
{
	///the function checks if the profile already exists in the repo, case in which it returns -1, which is treated as an error. 
	///if it doesnt already exist, the profile is added.
	if (searchProfileInRepositoryAfterId(profileToAdd.profileIdNumber, profilesRepository) != -1)
		return -1;
	profilesRepository->profiles[profilesRepository->length] = profileToAdd;
	profilesRepository->length++;
	return 1;
}

int deleteProfileFromRepository(char profileIdNumber[], ProfilesVector *profilesRepository)
{
	///the function checks if the profile already exists in the repo, if it doesnt it returns -1, which is treated as an error. 
	///if it exists, the profile is deleted.
	int index = searchProfileInRepositoryAfterId(profileIdNumber, profilesRepository);
	if (index == -1) {
		return -1;
	}
	profilesRepository->length--;
	int i;
	for (i = index ; i < profilesRepository->length ; i++) {
		profilesRepository->profiles[i] = profilesRepository->profiles[i + 1];
	}
	return 1;
}

int updateProfileInRepository(Profile profileToUpdate, ProfilesVector *profilesRepository)
{
	///the function checks if the profile already exists in the repo, if it doesnt it returns -1, which is treated as an error. 
	///if it exists, the profile is updated.
	int index = searchProfileInRepositoryAfterId(profileToUpdate.profileIdNumber, profilesRepository);
	if (index == -1) {
		return -1;
	}
	profilesRepository->profiles[index] = profileToUpdate;
	return 1;
}
