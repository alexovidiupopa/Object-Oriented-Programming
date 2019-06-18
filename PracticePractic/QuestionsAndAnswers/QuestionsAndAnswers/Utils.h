#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

class Utils
{

public:
	Utils();
	vector<string> tokenize(string input);
	~Utils();
};

