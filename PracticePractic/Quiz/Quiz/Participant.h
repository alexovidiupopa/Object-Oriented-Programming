#pragma once
#include "Utils.h"
class Participant
{
private:
	std::string name;
	int score;
public:
	Participant();
	Participant(std::string name,int score):name(name),score(score){}
	std::string getName() { return name; }
	int getScore() { return score; }
	void setName(std::string newName) { name = newName; }
	void setScore(int sc) { score = sc; }
	friend std::istream& operator>>(std::istream& stream, Participant &part);
	~Participant();
};

