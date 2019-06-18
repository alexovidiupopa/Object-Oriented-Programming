#pragma once
#include "Utils.h"

class Writer
{
private: 
	string name, expertise;
public:
	Writer();
	Writer(string name, string expertise) :name(name), expertise(expertise){}
	~Writer();
public:
    string getName() const;
    void setName(string name);

    string getExpertise() const;
    void setExpertise(string expertise);

	friend istream &operator>>(istream& stream, Writer& writer) {
		string input;
		getline(stream, input);
		vector<string> tokens = Utils::tokenize(input);
		if (tokens.size() != 2)
			return stream;
		writer.setName(tokens[0]);
		writer.setExpertise(tokens[1]);
		return stream;
	}
		
	

	string toString();

	
};

