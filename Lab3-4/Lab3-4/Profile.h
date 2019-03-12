#pragma once

typedef struct {
	char profileIdNumber[21];
	char placeOfBirth[21];
	char psychologicalProfile[21];
	int yearsOfRecordedService;
}Profile;

Profile createProfile(char profileIdNumber[], char placeOfBirth[], char psychologicalProfile[], int yearsOfRecordedService);

