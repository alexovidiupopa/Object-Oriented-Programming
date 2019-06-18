#include "Question.h"



Question::Question()
{
}


Question::~Question()
{
}

istream & operator>>(istream & stream, Question & question)
{
	string input;
	vector<string> tokens;
	Utils utils{};
	getline(stream, input);
	tokens = utils.tokenize(input);
	if (tokens.size() != 3)
		return stream;
	question.setId(std::stoi(tokens[0]));
	question.setText(tokens[1]);
	question.setName(tokens[2]);
	return stream;
}
