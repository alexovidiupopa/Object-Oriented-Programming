#pragma once
#include "Utils.h"

class User
{
private:
	string name;

public:
	User();
	User(string name):name(name){}
	string getName() { return name; }
	void setName(string newName) { name = newName; }
	friend istream& operator>>(istream &stream, User& user);
	string toString() { return name; }
	~User();
};

