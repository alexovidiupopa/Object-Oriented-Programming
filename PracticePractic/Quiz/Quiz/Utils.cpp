#pragma once
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> tokenize(std::string str)
{
	std::vector<std::string>tokens;
	std::stringstream strStream(str);
	std::string token;
	while (getline(strStream, token, ';'))
	{
		tokens.push_back(token);
	}
	return tokens;
}