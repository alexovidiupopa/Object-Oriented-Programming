#include "Repository.h"
#include <fstream>

#include <qdebug.h>
Repository::Repository()
{
	loadQuestions();
	loadParticipants();
}

void Repository::loadQuestions()
{
	std::ifstream f("questions.txt");
	Question q{};
	while (f >> q) {
		questions.push_back(&q);
	}
	f.close();
}

void Repository::loadParticipants()
{
	std::ifstream f("participants.txt");
	Participant p{};
	while (f >> p) {
		participants.push_back(&p);
	}
	f.close();
}


bool Repository::search(int id)
{
	for (auto q : questions) {
		if (q->getId() == id)
			return true;
	}
	return false;
}

void Repository::update(Question* q,std::string name)
{
	int score = q->getScore();
	for (auto p : participants) {
		if (p->getName() == name)
			p->setScore(score);
	}
}

void Repository::saveQuestions()
{
	std::ofstream g("questions.txt");
	for (auto q : questions) {
		g << q->toString();
	}
	g.close();
}

Repository::~Repository()
{
	
}
