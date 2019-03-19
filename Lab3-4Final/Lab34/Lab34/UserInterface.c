#include "UserInterface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uiAdd(DynamicArray *profilesRepository, char *splitCommand) {
	char profileIdNumber[21], psychologicalProfile[21], placeOfBirth[21], yearsOfService[11];
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

int uiUpdate(DynamicArray *profilesRepository, char *splitCommand) {
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

int uiDelete(DynamicArray *profilesRepository, char *splitCommand) {
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

int uiList(DynamicArray *profilesRepository, char *splitCommand) {

	char listOfProfiles[201];
	splitCommand = strtok(NULL, " ");
	if (splitCommand == NULL) {
		listProfiles(profilesRepository);
		//strcpy(listOfProfiles, listProfiles(profilesRepository));
		//rintf("%s", listOfProfiles);
	}
	else {
		char typeOfPsychologicalProfileToFilter[21];
		strcpy(typeOfPsychologicalProfileToFilter, splitCommand);
		splitCommand = strtok(NULL, " ");
		if (splitCommand != NULL) {
			return -1;
		}
		int yearsToFilter = atoi(typeOfPsychologicalProfileToFilter);
		if (yearsToFilter == 0) {
			listProfilesByPsychologicalProfile(profilesRepository, typeOfPsychologicalProfileToFilter);
		}
		else {
			listProfilesWithLessThanAGivenValue(profilesRepository, yearsToFilter);
		}
	}
	return 1;
}

void runConsole(DynamicArray *profilesRepository,DynamicArray *repositoryStack)
{
	addToArray(repositoryStack, profilesRepository);
	int undoRedoIndex = 0; 

	while (1) {
		char userInputString[101];
		char *splitCommand;
		char command[11];

		//printf("->");
		scanf(" %[^\n]s", userInputString);

		splitCommand = strtok(userInputString, " ");

		strcpy(command, splitCommand);

		DynamicArray* auxiliaryArray = repositoryStack->copyFct(repositoryStack->elements[undoRedoIndex]);

		//profilesRepository = repositoryStack->copyFct(repositoryStack->elements[undoRedoIndex]);

		int validOperation = -1;
		if (strcmp(command, "add") == 0) {
			validOperation = uiAdd(auxiliaryArray, splitCommand);
			
			if (validOperation == 1)
				addToArray(repositoryStack, auxiliaryArray);
				undoRedoIndex = repositoryStack->size-1;
		}
		else if (strcmp(command, "update") == 0) {
			validOperation = uiUpdate(auxiliaryArray, splitCommand);
			if (validOperation == 1)
				addToArray(repositoryStack, auxiliaryArray);
				undoRedoIndex = repositoryStack->size-1;
		}
		else if (strcmp(command, "delete") == 0) {
			validOperation = uiDelete(auxiliaryArray, splitCommand);
			if (validOperation == 1)
				addToArray(repositoryStack, auxiliaryArray);
				undoRedoIndex = repositoryStack->size-1;
		}
		else if (strcmp(command, "list") == 0) {
			validOperation = uiList(auxiliaryArray, splitCommand);
		}
		else if (strcmp(command, "undo") == 0) {
			if (undoRedoIndex > 0) {
				undoRedoIndex--;
				validOperation = 1;
			}
			else
				validOperation = -1;
		}
		else if (strcmp(command, "redo") == 0) {
			if (undoRedoIndex < auxiliaryArray->size+1) {
				undoRedoIndex++;
				validOperation = 1;
			}
			else
				validOperation = -1;
		}
		else if (strcmp(command, "exit") == 0) {
			destroyArray(auxiliaryArray);
			return;
		}
		if (validOperation < 0) {
			printf("Error when executing the command.");
			continue;
		}
		
		destroyArray(auxiliaryArray);
	}

}
