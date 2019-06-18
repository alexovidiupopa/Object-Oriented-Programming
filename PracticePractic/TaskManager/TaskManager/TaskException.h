#pragma once
#include <stdexcept>
#include <string>
class TaskException :
	public std::exception
{
private:
	std::string message;
public:
	TaskException(std::string message) :message(message) {};
	std::string what() { return message; }
	~TaskException();
};

