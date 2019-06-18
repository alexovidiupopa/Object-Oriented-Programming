#pragma once
#include "Utils.h"
class Answer
{
private:
	int id, questId,votes;
	string name, text;
	
public:
	Answer();
	Answer(int id, int questId, string name, string text, int votes):id(id),questId(questId),name(name),text(text),votes(votes){}
	~Answer();
public:
    int getId() const;
    void setId(int id);

    int getQuestId() const;
    void setQuestId(int questId);

    int getVotes() const;
    void setVotes(int votes);

    string getName() const;
    void setName(string name);

    string getText() const;
    void setText(string text);

	friend istream& operator>>(istream& stream, Answer &answer);

	string toString() {
		string str="";
		str += to_string(id) + ";" + to_string(questId) + ";" + name + ";" + text + ";" + to_string(votes) + "\n";
		return str;
	}

};

