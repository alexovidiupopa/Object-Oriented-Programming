#include "Repository.h"



void Repository::loadUsers()
{
	ifstream f("users.txt");
	User user{};
	while (f >> user)
		users.push_back(user);
	f.close();
}

void Repository::loadQuestions()
{
	ifstream f("questions.txt");
	Question quest{};
	while (f >> quest)
		questions.push_back(quest);
	f.close();
}

void Repository::loadAnswers()
{
	ifstream f("answers.txt");
	Answer answ{};
	while (f >> answ)
		answers.push_back(answ);
	f.close();
}

void Repository::saveQuestions()
{
	ofstream g("questions.txt");
	for (auto quest : questions)
		g << quest.toString();
	g.close();
}

void Repository::saveAnswers()
{
	ofstream g("answers.txt");
	for (auto answ : answers)
		g << answ.toString();
	g.close();
}

Repository::Repository()
{
	loadUsers();
	loadQuestions();
	loadAnswers();
}

vector<Question> Repository::getQuestions()
{
	return questions;
}

vector<Question> Repository::getQuestionsSorted()
{
	for (auto &quest : questions) {
		int count = 0;
		for (auto ans : answers) {

			if (ans.getQuestId() == quest.getId())
				count++;
		}
		quest.setAnswer(count);
	}
	vector<Question> result = questions;
	sort(result.begin(), result.end(), [](Question q1, Question q2) {return q1.getAnswers() > q2.getAnswers(); });
	return result;
}


Repository::~Repository()
{
}
