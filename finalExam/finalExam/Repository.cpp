#include "Repository.h"



void Repository::loadWriters()
{
	ifstream input("writers.txt");
	Writer writer{};
	while (input >> writer)
		writers.push_back(writer);
	input.close();
}

void Repository::loadIdeas()
{
	ifstream input("ideas.txt");
	Idea idea{};
	while (input >> idea)
		ideas.push_back(idea);
	input.close();
}

bool Repository::searchForIdea(Idea idea)
{
	for (auto allIdeas : ideas)
		if (allIdeas.getDescription() == idea.getDescription() && allIdeas.getAct()==idea.getAct())
			return true;
	return false;
}

Repository::Repository(bool load)
{
	if (load)
	{
		loadIdeas();
		loadWriters();
	}
}

vector<Idea>& Repository::getIdeas()
{
	return ideas;
}

vector<Writer>& Repository::getWriters()
{
	return writers;
}

/*SPECIFICATIONS FOR THE ADD IDEA METHOD
INPUT PARAMETERS: idea - an object of type Idea
OUTPUT PARAMETERS: none
THROWS: std::exception() if the idea we are trying to add is already in the repository
REMARKS: If it's not in the repository, it is added to the ideas vector*/

void Repository::addIdea(Idea idea)
{
	if (searchForIdea(idea))
		throw exception("Already existing idea!");
	ideas.push_back(idea);
}

/*SPECIFICATIONS FOR THE IDEA METHOD
INPUT PARAMETERS: ideaToAccept - an object of type idea which represents the idea we want accepted
OUTPUT PARAMETERS: none
REMARKS: Two ideas are the same if they have the same description and act.
The function iterates through the ideas until it finds the one passed as a parameter 
and when it does find it, its status is updated to "accepted"*/
void Repository::acceptIdea(Idea ideaToAccept)
{
	for (auto& idea : ideas)
		if (idea.getDescription() == ideaToAccept.getDescription() && idea.getAct()==ideaToAccept.getAct() && idea.getStatus()!="accepted")
		{
			idea.setStatus("accepted");
			return;
		}
}

void Repository::savePlot()
{
	ofstream output("plot.txt");
	vector<Idea> ideasThatCanBeSaved = buildPlotIdeas();
	output << "Act 1:" << endl;
	for (auto idea : ideasThatCanBeSaved)
	{
		if (idea.getAct() == "1")
			output << "Description:" << idea.getDescription() << " (" << idea.getCreator() << ")" << endl;
	}
	output << "Act 2:" << endl;
	for (auto idea : ideasThatCanBeSaved)
	{
		if (idea.getAct() == "2")
			output << "Description:" << idea.getDescription() << " (" << idea.getCreator() << ")" << endl;
	}
	output << "Act 3:" << endl;
	for (auto idea : ideasThatCanBeSaved)
	{
		if (idea.getAct() == "3")
			output << "Description:" << idea.getDescription() << " (" << idea.getCreator() << ")" << endl;
	}

	output.close();
}

vector<Idea> Repository::buildPlotIdeas()
{
	vector<Idea> ideasThatCanBeSaved;
	for (auto idea : ideas)
	{
		if (idea.getStatus() == "accepted")
			ideasThatCanBeSaved.push_back(idea);
	}
	return ideasThatCanBeSaved;
}

Repository::~Repository()
{
}
