#include "Validator.h"
#include <cstring>
bool Validator::validateTitle(char givenTitle[])
{
	return strlen(givenTitle) > 2;
}

bool Validator::validateFilmedAt(char givenFilmedAt[])
{
	return strlen(givenFilmedAt) > 5;
}

bool Validator::validateCreationDate(char givenCreationDate[])
{
	return strstr(givenCreationDate, "2019") != NULL;
}

bool Validator::validateFootagePreview(char givenFootagePreview[])
{
	return strstr(givenFootagePreview, ".mp4") != NULL;
}

bool Validator::validateAccessCount(int givenAccessCount)
{
	return givenAccessCount >= 0;
}

bool Validator::validateData(char givenTitle[], char givenFilmedAt[], char givenCreationDate[], char givenFootagePreview[], int givenAccessCount)
{
	return validateTitle(givenTitle) && validateFilmedAt(givenFilmedAt) && validateCreationDate(givenCreationDate) && validateFootagePreview(givenFootagePreview) && validateAccessCount(givenAccessCount);
}
