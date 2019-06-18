#pragma once
#include <string>
#include <sstream>
#include <vector>
class Utils
{
public:
	Utils();
	std::vector<std::string> tokenize(std::string input);
	~Utils();
};

