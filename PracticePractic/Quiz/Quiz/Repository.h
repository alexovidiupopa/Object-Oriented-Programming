#pragma once
#include "Participant.h"
#include "Question.h"
class Repository
{
private:
	std::vector<Question*> questions;
	std::vector<Participant*> participants;
public:
	Repository();
	void loadQuestions();
	void loadParticipants();
	std::vector<Question*> getQ() { return questions; }
	std::vector<Participant*> getP() { return participants; }
	bool search(int id);
	void update(Question* q,std::string name);
	void addQ(Question *q) { 
		questions.push_back(q); 
		saveQuestions();
	}
	int getScoreRepo(std::string name) {
		for (auto p : participants)
			if (p->getName() == name)
				return p->getScore();
	}
	void saveQuestions();
	~Repository();
};

