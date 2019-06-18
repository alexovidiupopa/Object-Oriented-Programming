#include "Programmer.h"


Programmer::Programmer()
{
}


Programmer::~Programmer()
{
}


std::istream & operator>>(std::istream & stream, Programmer & prog)
{
	std::string input;
	getline(stream,input);
	Utils u{};
	std::vector< std::string> tokens = u.tokenize(input);
	if (tokens.size() != 2) {
		return stream;
	}
	prog.setName(tokens[0]);
	prog.setId(std::stoi(tokens[1]));
	return stream;
}
