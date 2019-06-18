#include "User.h"



User::User()
{
}


User::~User()
{
}

istream & operator>>(istream & stream, User & user)
{
	string input;
	vector<string> tokens;
	Utils utils{};
	getline(stream,input);
	tokens = utils.tokenize(input);
	if (tokens.size() != 1)
		return stream;
	user.setName(tokens[0]);
	return stream;
}
