#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <assert.h>
using namespace std;
class Utils
{
public:
	Utils();
	static vector<string> tokenize(string input) {
		stringstream stream(input);
		vector<string> tokens;
		string token;
		while (getline(stream, token, ';'))
			tokens.push_back(token);
		return tokens;
	}
	~Utils();
};

