#pragma once
#include "Utils.h"
class User
{
private:
	string name, type;
public:
	User();
	~User();
public:
    string getName() const;
    void setName(string name);

    string getType() const;
    void setType(string type);

	string toString() { return name + ";" + type + "\n"; }
	friend istream& operator>>(istream& stream, User& user);

};

