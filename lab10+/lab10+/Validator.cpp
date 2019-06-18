#include "Validator.h"

void Validator::validateTitle(std::string givenTitle)
{
	if (givenTitle == "")
		throw ValidatorException("Invalid title");
}

void Validator::validateFilmedAt(std::string  givenFilmedAt)
{
	if (givenFilmedAt == "")
		throw ValidatorException("Invalid filmedAt");
}

void Validator::validateCreationDate(std::string  givenCreationDate)
{
	if (givenCreationDate == "")
		throw ValidatorException("Invalid creation date");
}

void Validator::validateFootagePreview(std::string  givenFootagePreview)
{
	if (givenFootagePreview == "")
		throw ValidatorException("Invalid footage preview");
}

void Validator::validateAccessCount(int givenAccessCount)
{
	if (givenAccessCount <= 0)
		throw ValidatorException("Invalid access count");
}

void Validator::validateData(std::string  givenTitle, std::string  givenFilmedAt, std::string  givenCreationDate, std::string  givenFootagePreview, int givenAccessCount)
{
	std::string exception="";
	try {
		validateTitle(givenTitle);
	}
	catch (ValidatorException &ve) {
		exception += ve.getMessage();
		exception += "\n";
	}
	try {
		validateFilmedAt(givenFilmedAt);
	}
	catch (ValidatorException &ve) {
		exception += ve.getMessage();
		exception += "\n";
	}
	try {
		validateCreationDate(givenCreationDate);
	}
	catch (ValidatorException &ve) {
		exception += ve.getMessage();
		exception += "\n";
	}
	try {
		validateFootagePreview(givenFootagePreview);
	}
	catch (ValidatorException &ve) {
		exception += ve.getMessage();
		exception += "\n";
	}
	try {
		validateAccessCount(givenAccessCount);
	}
	catch (ValidatorException &ve) {
		exception += ve.getMessage();
	}
	if (exception != "")
		throw ValidatorException(exception);

}
