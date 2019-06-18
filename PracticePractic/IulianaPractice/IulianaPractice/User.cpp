#include "User.h"



User::User()
{
}


User::~User()
{
}

string User::getName() const
{
    return name;
}

void User::setName(string name)
{
    this->name = name;
}

string User::getType() const
{
    return type;
}

void User::setType(string type)
{
    this->type = type;
}

istream & operator>>(istream & stream, User & user)
{
	string input;
	getline(stream,input);
	Utils utils{};
	vector<string> tokens = utils.tokenize(input);
	if (tokens.size() != 2)
		return stream;
	user.setName(tokens[0]);
	user.setType(tokens[1]);
	return stream;
}
