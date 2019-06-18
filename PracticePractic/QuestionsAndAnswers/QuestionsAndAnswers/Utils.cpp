#include "Utils.h"



Utils::Utils()
{
}

vector<string> Utils::tokenize(string input)
{
	vector<string> tokens;
	string token;
	stringstream strstream(input);
	while (getline(strstream, token, ';'))
		tokens.push_back(token);
	return tokens;
}


Utils::~Utils()
{
}
