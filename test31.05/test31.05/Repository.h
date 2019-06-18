#pragma once
#include "Document.h"
#include <fstream>
class Repository
{
private: 
	std::vector<Document> documents;
	void loadFile() {
		std::ifstream fileInput("input.txt");
		Document document{};
		while (fileInput >> document) {
			documents.push_back(document);
		}
		fileInput.close();
	}
public:
	Repository();
	std::vector<Document> getRepository() { return documents; }
	std::vector<Document> getPartialMatchingDocuments(std::string match){
		std::vector<Document> filteredVector;
		for (auto document : documents) {
			if (document.getName().find(match) != std::string::npos || document.getKeywords().find(match) != std::string::npos)
				filteredVector.push_back(document);
		}
		return filteredVector;
	}
	~Repository();
};

