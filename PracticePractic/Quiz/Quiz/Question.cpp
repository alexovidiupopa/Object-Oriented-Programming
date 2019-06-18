#include "Question.h"



Question::Question():id(0),text(""),score(0),answer("")
{
}


Question::~Question()
{
}

std::istream & operator>>(std::istream & stream, Question & ques)
{
	// TODO: insert return statement here
	std::string str;
	getline(stream, str);
	std::vector<std::string>tokens;
	tokens = tokenize(str);
	if (tokens.size() != 4)
		return stream;
	ques.setId(std::stoi(tokens[0]));
	ques.setText(tokens[1]);
	ques.setAnswer(tokens[2]);
	ques.setScore(std::stoi(tokens[3]));
	return stream;

}
