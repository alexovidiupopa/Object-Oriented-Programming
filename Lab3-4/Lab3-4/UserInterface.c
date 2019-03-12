#include "UserInterface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uiAdd(ProfilesVector *profilesRepository, char *splitCommand) {
	char profileIdNumber[21], psychologicalProfile[21], placeOfBirth[21],yearsOfService[11];
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(profileIdNumber, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(placeOfBirth, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(psychologicalProfile, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(yearsOfService, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand != NULL) {
		return -1;
	}

	return addProfile(profilesRepository, profileIdNumber, placeOfBirth, psychologicalProfile, atoi(yearsOfService));
}

int uiUpdate(ProfilesVector *profilesRepository, char *splitCommand) {
	char profileIdNumber[21], newPsychologicalProfile[21], newPlaceOfBirth[21], newYearsOfService[11];
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(profileIdNumber, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(newPlaceOfBirth, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(newPsychologicalProfile, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(newYearsOfService, splitCommand);
	splitCommand = strtok(NULL, ", ");
	if (splitCommand != NULL) {
		return -1;
	}

	return updateProfile(profilesRepository, profileIdNumber, newPlaceOfBirth, newPsychologicalProfile, atoi(newYearsOfService));
}

int uiDelete(ProfilesVector *profilesRepository, char *splitCommand) {
	char profileIdNumber[21];
	splitCommand = strtok(NULL, " ");
	if (splitCommand == NULL) {
		return -1;
	}
	strcpy(profileIdNumber, splitCommand);
	splitCommand = strtok(NULL, " ");
	if (splitCommand != NULL) {
		return -1;
	}

	return deleteProfile(profilesRepository, profileIdNumber);
}

int uiList(ProfilesVector *profilesRepository, char *splitCommand) {
	
	char listOfProfiles[201];
	splitCommand = strtok(NULL, " ");
	if (splitCommand == NULL) {
		strcpy(listOfProfiles, listProfiles(profilesRepository));
		printf("%s", listOfProfiles);
	}
	else {
		char typeOfPsychologicalProfileToFilter[21];
		strcpy(typeOfPsychologicalProfileToFilter, splitCommand);
		splitCommand = strtok(NULL, " ");
		if (splitCommand != NULL) {
			return -1;
		}
		strcpy(listOfProfiles, listProfilesByPsychologicalProfile(profilesRepository,typeOfPsychologicalProfileToFilter));
		printf("%s", listOfProfiles);
	}

	return 1;
}

void runConsole(ProfilesVector *profilesRepository)
{
	while (1) {
		char userInputString[101];
		char *splitCommand; 
		char command[11];
		//printf("->");
		scanf( " %[^'\n']s", userInputString);
		
		splitCommand = strtok(userInputString, " ");

		strcpy(command, splitCommand);

		int validOperation = -1;
		if (strcmp(command, "add") == 0) {
			validOperation = uiAdd(profilesRepository, splitCommand);
		}
		else if (strcmp(command, "update") == 0) {
			validOperation = uiUpdate(profilesRepository, splitCommand);
		}
		else if (strcmp(command, "delete") == 0) {
			validOperation = uiDelete(profilesRepository, splitCommand);
		}
		else if (strcmp(command, "exit") == 0) {
			return; 
		}
		else if (strcmp(command, "list") == 0) {
			validOperation = uiList(profilesRepository,splitCommand);
		}
		if (validOperation < 0) {
			printf("Error when executing the command.");
		}
	}
	
}
