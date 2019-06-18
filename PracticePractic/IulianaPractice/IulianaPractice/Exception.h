#pragma once
#include <stdexcept>
#include "Utils.h"
class Exception :
	public std::exception
{
private:
	string message;
public:
	Exception();
	Exception(string message):message(message){}
	string getMsg() { return message; }
	~Exception();
};

