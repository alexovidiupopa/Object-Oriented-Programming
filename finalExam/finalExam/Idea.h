#pragma once
#include "Utils.h"
class Idea
{
private:
	string description, status, creator, act;
public:
	Idea();
	Idea(string desc, string status, string creator, string act) :description(desc), status(status),
		creator(creator), act(act) {}
	~Idea();
public:
	string getDescription() const;
	void setDescription(string description);

	string getStatus() const;
	void setStatus(string status);

	string getCreator() const;
	void setCreator(string creator);

	string getAct() const;
	void setAct(string act);

	string toString();

	friend istream& operator>>(istream& stream, Idea& idea)
	{
		string input;
		getline(stream, input);
		vector<string> tokens = Utils::tokenize(input);
		if (tokens.size() != 4)
			return stream;
		idea.setDescription(tokens[0]);
		idea.setStatus(tokens[1]);
		idea.setCreator(tokens[2]);
		idea.setAct(tokens[3]);
		return stream;
	}
};

