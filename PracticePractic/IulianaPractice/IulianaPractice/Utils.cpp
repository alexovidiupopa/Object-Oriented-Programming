#include "Utils.h"



Utils::Utils()
{
}

vector<string> Utils::tokenize(string input)
{
	vector<string> tokens;
	string token;
	stringstream str(input);
	while (getline(str, token, ';'))
		tokens.push_back(token);
	return tokens;
}


Utils::~Utils()
{
}
