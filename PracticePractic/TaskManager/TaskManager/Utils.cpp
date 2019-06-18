#include "Utils.h"



Utils::Utils()
{
}

std::vector< std::string> Utils::tokenize(std::string input)
{
	std::vector< std::string> tokens;
	std::string token;
	std::stringstream stringStream(input);
	while (getline(stringStream, token, ';'))
	{
		tokens.push_back(token);
	}
	return tokens;
}

Utils::~Utils()
{
}
