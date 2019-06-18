#pragma once
#include "Utils.h"
class Question
{
private:
	int id;
	string text, name;
	int answers;
public:
	Question();
	Question(int id,string text,string name):id(id),text(text),name(name),answers(0){}
	int getId() { return id; }
	string getText() { return text; }
	string getName() { return name; }
	int getAnswers() { return answers; }
	void setId(int newId) { id = newId; }
	void setText(string newText) { text = newText; }
	void setName(string newName) { name = newName; }
	void setAnswer(int answerss) { answers = answerss; }
	string toString() {
		string str = "";
		str += std::to_string(id) + ";" + text + ";" + name +  "\n";
		return str;
	}
	friend istream& operator>>(istream &stream, Question &question);
	~Question();
};

