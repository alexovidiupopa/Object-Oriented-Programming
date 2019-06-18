#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository &repository;
public:
	Controller(Repository &repository);
	vector<Idea> &getIdeas();
	vector<Writer> getWriters();
	vector<Idea>&getIdeasSorted();

	void addIdea(string description, string creator, string act);
	void acceptIdea(int numberOfIdea);
	void savePlotController();
	~Controller();
};

