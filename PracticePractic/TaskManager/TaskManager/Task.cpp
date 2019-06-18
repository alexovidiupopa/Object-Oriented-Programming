#include "Task.h"



Task::Task()
{
}


Task::~Task()
{
}

std::istream & operator>>(std::istream & stream, Task & task)
{
	std::string input;
	getline(stream, input);
	Utils u{};
	std::vector< std::string> tokens = u.tokenize(input);
	if (tokens.size() != 3) {
		return stream;
	}
	task.setDescription(tokens[0]);
	task.setStatus(tokens[1]);
	task.setId(std::stoi(tokens[2]));
	return stream;
}
