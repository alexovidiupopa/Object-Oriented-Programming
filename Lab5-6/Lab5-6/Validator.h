#pragma once
#include <string>
#include "Exceptions.h"
class Validator {

private: 

	void validateTitle(std::string givenTitle);
	void validateFilmedAt(std::string givenFilmedAt);
	void validateCreationDate(std::string givenCreationDate);
	void validateFootagePreview(std::string givenFootagePreview);
	void validateAccessCount(int givenAccessCount);

public:

	void validateData(std::string  givenTitle, std::string  givenFilmedAt, std::string  givenCreationDate, std::string  givenFootagePreview, int givenAccessCount);
};