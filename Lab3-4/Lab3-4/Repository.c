#include "Repository.h"
#include <string.h>

ProfilesVector* createRepository(int capacity)
{
	ProfilesVector* profilesRepository = (ProfilesVector*)malloc(sizeof(ProfilesVector));
	profilesRepository->capacity = capacity;
	profilesRepository->length = 0;
	profilesRepository->profiles = (Profile*)malloc(sizeof(Profile)*capacity);
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
	if (profilesRepository->length == profilesRepository->capacity) {
		resize(profilesRepository);
	}
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

void destroyRepository(ProfilesVector* profilesRepository)
{
	if (profilesRepository == NULL)
		return;

	for (int i = 0; i < profilesRepository->length; i++) {
		destroyProfile(profilesRepository->profiles[i]);
	}
	free(profilesRepository->profiles);
	free(profilesRepository);
}

void resize(ProfilesVector * profilesRepository)
{
	profilesRepository->capacity *= 2;
	Profile* newProfiles = malloc(sizeof(Profile)*profilesRepository->capacity);
	for (int i = 0; i < profilesRepository->length; i++) {
		newProfiles[i] = profilesRepository->profiles[i];
	}
	free(profilesRepository->profiles);
	profilesRepository->profiles = newProfiles;
}

ProfilesVector * profilesWithLessThanAGivenValue(ProfilesVector * profileRepository,int givenValue)
{
	ProfilesVector *temporaryProfiles = createRepository(profileRepository->capacity);
	for (int i = 0; i < profileRepository->length; i++) {
		if (profileRepository->profiles[i].yearsOfRecordedService < givenValue) {
			addProfileToRepository(profileRepository->profiles[i], temporaryProfiles);
		}
	}
	return temporaryProfiles;
}

RepositoryStack * createUndoRedoStack(int capacity)
{
	RepositoryStack* stack = (RepositoryStack*)malloc(sizeof(RepositoryStack));
	stack->capacity = capacity;
	stack->length = 0;
	stack->index = 0;
	stack->repositories = (ProfilesVector*)malloc(sizeof(ProfilesVector)*capacity);
	return stack;
}

void resizeStack(RepositoryStack * stack)
{
	stack->capacity *= 2;
	ProfilesVector* newProfilesVector = malloc(sizeof(ProfilesVector)*stack->capacity);
	for (int i = 0; i < stack->length; i++) {
		newProfilesVector[i] = stack->repositories[i];
	}
	free(stack->repositories);
	stack->repositories = newProfilesVector;
}

void destroyStack(RepositoryStack * stack)
{
	if (stack == NULL)
		return;
	for (int i = 0; i < stack->length; i++) {

		for (int j = 0; j < stack->repositories[i].length; i++) {
			free(stack->repositories[i].profiles[j].profileIdNumber);
			free(stack->repositories[i].profiles[j].placeOfBirth);
			free(stack->repositories[i].profiles[j].psychologicalProfile);
		}
		//free(&stack->repositories[i]);
	}
	free(stack->repositories);
	free(stack);
}

ProfilesVector  copyRepository(ProfilesVector * repository)
{
	ProfilesVector newProfilesVector;
	newProfilesVector.capacity = repository->capacity;
	newProfilesVector.length = repository->length;
	newProfilesVector.profiles = (Profile*)malloc(sizeof(Profile)*newProfilesVector.capacity);
	for (int i = 0; i < newProfilesVector.length; i++)
		newProfilesVector.profiles[i] = repository->profiles[i];
	return newProfilesVector;
}

void addToStack(RepositoryStack* stack, ProfilesVector* repoToAdd)
{
	if (stack->length == stack->capacity)
		resizeStack(stack);
	stack->repositories[stack->length++] = copyRepository(repoToAdd);
	
}

void replaceRepository(ProfilesVector *oldRepo, ProfilesVector newRepo)
{
	oldRepo->length = newRepo.length;
	oldRepo->capacity = newRepo.capacity;
	for (int i = 0; i < oldRepo->length; i++)
		oldRepo->profiles[i] = newRepo.profiles[i];
	
}