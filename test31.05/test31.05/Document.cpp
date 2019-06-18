#include "Document.h"
#include <sstream>

Document::Document()
{
}


std::vector<std::string> tokenize(std::string input)
{
	std::vector<std::string>tokens;
	std::string token;
	std::stringstream stringStream(input);
	while (getline(stringStream, token, '|')) {
		tokens.push_back(token);
	}
	return tokens;
}

Document::~Document()
{
}

std::istream & operator>>(std::istream & stream, Document &document)
{
	std::string input;
	getline(stream, input);
	std::vector<std::string> tokens = tokenize(input);
	if (tokens.size() == 0)
		return stream;
	document.setName(tokens[0]);
	document.setKeywords(tokens[1]);
	document.setContent(tokens[2]);
	return stream;
}
