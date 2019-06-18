#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

class Utils
{
	
public:
	Utils();
	vector<string> tokenize(string input);
	~Utils();
};

