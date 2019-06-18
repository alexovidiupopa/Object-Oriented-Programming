#pragma once
#include "Repository.h"
#include "Observer.h"
class Controller : public Subject
{
private: 
	Repository * repo;
public:
	Controller(Repository* repo):repo(repo),Subject(){}
	std::vector <Question*> getQuestions();
	std::vector <Question*> getQuestionsSortedByID();
	std::vector <Question*> getQuestionsSortedByScore();
	std::vector<Participant*> getParticipants();
	bool add(int id, std::string text, std::string answer);
	bool answer(std::string answer,int row,std::string name) {
		Question* q = getQuestionsSortedByScore()[row];
		if (q->getAnswer() == answer)
		{
			repo->update(q,name);
			return true;
		}
		return false;
	}
	int getCurrentScore(std::string name) {
		return repo->getScoreRepo(name);
	}
	~Controller();
};

