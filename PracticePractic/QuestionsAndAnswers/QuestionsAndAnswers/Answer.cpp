#include "Answer.h"



Answer::Answer()
{
}


Answer::~Answer()
{
}

int Answer::getId() const
{
    return id;
}

void Answer::setId(int id)
{
    this->id = id;
}

int Answer::getQuestId() const
{
    return questId;
}

void Answer::setQuestId(int questId)
{
    this->questId = questId;
}

int Answer::getVotes() const
{
    return votes;
}

void Answer::setVotes(int votes)
{
    this->votes = votes;
}

string Answer::getName() const
{
    return name;
}

void Answer::setName(string name)
{
    this->name = name;
}

string Answer::getText() const
{
    return text;
}

void Answer::setText(string text)
{
    this->text = text;
}

istream & operator>>(istream & stream, Answer & answer)
{
	string input;
	vector<string> tokens;
	Utils utils{};
	getline(stream, input);
	tokens = utils.tokenize(input);
	if (tokens.size() != 5)
		return stream;
	answer.setId(std::stoi(tokens[0]));
	answer.setQuestId(std::stoi(tokens[1]));
	answer.setText(tokens[3]);
	answer.setName(tokens[2]);
	answer.setVotes(std::stoi(tokens[4]));
	return stream;
}
