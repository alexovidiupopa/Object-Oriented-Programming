#include "Controller.h"



Controller::Controller(Repository &repository): repository(repository)
{
}

vector<Idea>& Controller::getIdeas()
{
	return repository.getIdeas();
}


vector<Writer> Controller::getWriters()
{
	return repository.getWriters();
}

vector<Idea>& Controller::getIdeasSorted()
{
	vector<Idea> &sorted = repository.getIdeas();
	sort(sorted.begin(), sorted.end(), [](Idea idea1, Idea idea2)
	{
		return idea1.getAct() < idea2.getAct();
	});
	return sorted;
}

void Controller::addIdea(string description, string creator, string act)
{
	if (description == "" || (act != "1" && act != "2" && act != "3"))
		throw exception("Invalid data");
	repository.addIdea(Idea{ description,"proposed",creator,act });
}

void Controller::acceptIdea(int numberOfIdea)
{
	Idea ideaToAccept = getIdeasSorted()[numberOfIdea];
	repository.acceptIdea(ideaToAccept);
}

void Controller::savePlotController()
{
	repository.savePlot();
}

Controller::~Controller()
{
}
