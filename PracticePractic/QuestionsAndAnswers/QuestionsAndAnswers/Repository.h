#pragma once
#include "Answer.h"
#include "Question.h"
#include "User.h"
class Repository
{
private: 
	vector<User> users;
	vector<Answer> answers;
	vector<Question> questions;
	void loadUsers();
	void loadQuestions();
	void loadAnswers();
	void saveQuestions();
	void saveAnswers();
public:
	Repository();
	vector<Question> getQuestions();
	vector<Question> getQuestionsSorted();
	vector<Answer> getAnswers() {return answers; }
	vector<User> getUsers() { return users; }
	void addQuestion(Question q) {
		questions.push_back(q);
		saveQuestions();
	}
	void addAnswer(Answer a) {
		answers.push_back(a);
		saveAnswers();

	}
	~Repository();
};

