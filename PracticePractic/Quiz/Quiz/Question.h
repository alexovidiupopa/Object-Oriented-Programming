#pragma once
#include "Utils.h"
class Question
{
private:
	std::string text, answer;
	int id, score;
public:
	Question();
	Question(int id, std::string text, std::string answer, int score):id(id),text(text),answer(answer),score(score){}
	std::string getText() { return text; }
	std::string getAnswer() { return answer; }
	int getId() { return id; }
	int getScore() { return score; }
	void setText(std::string newText) { text = newText; }
	void setId(int newID) { id = newID; }
	void setScore(int newScore) { score = newScore; }
	void setAnswer(std::string newAnsw) { answer = newAnsw; }
	friend std::istream& operator>>(std::istream& stream, Question& ques);
	std::string toString() { std::string str;
	str += std::to_string(id);
	str += ";" + text + ";" + answer + ";" + std::to_string(score) + "\n";
	return str;
	}
	~Question();
};

