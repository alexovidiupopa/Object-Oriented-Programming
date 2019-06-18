#pragma once
#include "Repository.h"

class Controller
{
private: 
	Repository repository{};
public:
	Controller();
	std::vector<Document> getDocuments() { return repository.getRepository(); }
	std::vector<Document> getPartialMatching(std::string match) {
		return repository.getPartialMatchingDocuments(match);
	}

	/*SPECIFICATIONS for getBestMatch() method:
	INPUT PARAMETER - match - std::string = the string we want to match for 
	OUT PARAMETER - an object of type Document representing the best matching document for the string passed 
			as a parameter
	RESTRICTIONS: - 
	HOW IT WORKS: The function gets the previous result from the matching and then uses the provided formula 
	to find the maximum matching Document from the previous result. 
	Said document is returned at the end.
	REMARKS: the computation was done using the find function provided by the string library.*/
	Document getBestMatch(std::string match) {
		std::vector<Document> partialMatchingResult = repository.getPartialMatchingDocuments(match);
		float maximumCharacters = 0;
		int  positionOfMaximum = -1;
		for (int i = 0; i < partialMatchingResult.size();i++) {
			int positionOfSubstring = 0;
			partialMatchingResult[i].getName().find(match, positionOfSubstring);
			int nameLength = partialMatchingResult[i].getName().length();
			if (float((nameLength - positionOfSubstring)/nameLength) > maximumCharacters) {
				maximumCharacters = float((nameLength - positionOfSubstring) / nameLength);
				positionOfMaximum = i;
			}
		}
		return partialMatchingResult[positionOfMaximum];
	}
	~Controller();
};

