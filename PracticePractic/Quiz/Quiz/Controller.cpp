#include "Controller.h"
#include <algorithm>


std::vector<Question*> Controller::getQuestions()
{
	return repo->getQ();
}

std::vector<Question*> Controller::getQuestionsSortedByID()
{
	std::vector<Question*> questions = repo->getQ();
	std::sort(questions.begin(), questions.end(), [](Question* q1, Question* q2) {return q1->getId() < q2->getId(); });
	return questions;
}

std::vector<Question*> Controller::getQuestionsSortedByScore()
{
	std::vector<Question*> questions = repo->getQ();
	std::sort(questions.begin(), questions.end(), [](Question* q1, Question* q2) {return q1->getScore() > q2->getScore(); });
	return questions;
}

bool Controller::add(int id, std::string text, std::string answer)
{
	if (text == "" || repo->search(id))
		return false;
	repo->addQ(new Question{ id,text,answer,0 });
	notify();
	return true;
}
std::vector<Participant*> Controller::getParticipants()
{
	return repo->getP();
}

Controller::~Controller()
{
	delete repo;
}
