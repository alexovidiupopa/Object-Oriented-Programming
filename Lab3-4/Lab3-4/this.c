void runConsole(Vector* fileRepository, Vector* repositoryHistory) {
	char* command = (char*)malloc(sizeof(char) * 100);
	char* input = (char*)malloc(sizeof(char) * 100);
	char* token;
	addToVector(repositoryHistory, fileRepository);
	int currentIndexInHistory = 0;
	bool inputNotExit = true;
	while (inputNotExit) {
		scanf(" %[^\n]s", input);
		token = strtok(input, " ");
		strcpy(command, token);
		Vector* currentVector = repositoryHistory->copyFunction(repositoryHistory->buffer[currentIndexInHistory]);
		if (strcmp(command, "add") == 0) {
			if (UIAdd(currentVector, token)) {
				removeAllFromIndex(repositoryHistory, currentIndexInHistory + 1);
				addToVector(repositoryHistory, currentVector);
				currentIndexInHistory = repositoryHistory->size - 1;
			}
		}
		else if (strcmp(command, "delete") == 0) {
			if (UIDelete(currentVector, token)) {
				removeAllFromIndex(repositoryHistory, currentIndexInHistory + 1);
				addToVector(repositoryHistory, currentVector);
				currentIndexInHistory = repositoryHistory->size - 1;
			}
		}
		else if (strcmp(command, "update") == 0) {
			if (UIUpdate(currentVector, token)) {
				removeAllFromIndex(repositoryHistory, currentIndexInHistory + 1);
				addToVector(repositoryHistory, currentVector);
				currentIndexInHistory = repositoryHistory->size - 1;
			}
		}
		else if (strcmp(command, "list") == 0) {
			UIList(currentVector, token);
		}
		else if (strcmp(command, "undo") == 0) {
			if (currentIndexInHistory > 0) {
				currentIndexInHistory--;
			}
		}
		else if (strcmp(command, "redo") == 0) {
			if (currentIndexInHistory < repositoryHistory->size - 1) {
				currentIndexInHistory++;
			}
		}
		else if (strcmp(input, "exit") == 0) {
			inputNotExit = false;
		}
		destroyVector(currentVector);
	}
	FREE(command);
	FREE(input);
}