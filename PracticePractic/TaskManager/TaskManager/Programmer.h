#pragma once
#include "Utils.h"
class Programmer
{
private:
	std::string name;
	int id;

public:
	Programmer();
	Programmer(std::string name,int id):name(name),id(id){}
	int getId() { return id; }
	std::string getName() { return name; }
	void setId(int newid) { id = newid; }
	void setName(std::string newName) { name = newName; }
	std::string toString() {
		std::string str = name;
		str += ";" + std::to_string(id) + "\n";
		return str;
	}
	friend std::istream& operator>>(std::istream& stream, Programmer& prog);
	~Programmer();
};

