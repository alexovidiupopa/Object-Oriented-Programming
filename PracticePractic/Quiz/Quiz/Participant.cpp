#include "Participant.h"



Participant::Participant()
{
}


Participant::~Participant()
{
}

std::istream & operator>>(std::istream & stream, Participant & part)
{
	// TODO: insert return statement here
	std::string str;
	getline(stream, str);
	std::vector< std::string> tokens = tokenize(str);
	if (tokens.size() != 2)
		return stream;
	part.setName(tokens[0]);
	part.setScore(std::stoi(tokens[1]));
	return stream;
}
