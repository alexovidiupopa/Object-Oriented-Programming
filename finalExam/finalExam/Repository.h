#pragma once
#include "Idea.h"
#include "Writer.h"
class Repository
{
private:
	vector<Idea> ideas;
	vector<Writer> writers;
	void loadWriters();
	void loadIdeas();
	bool searchForIdea(Idea idea);
public:
	Repository(bool load);
	vector<Idea>& getIdeas();
	vector<Writer>& getWriters();
	void addIdea(Idea idea);
	void acceptIdea(Idea ideaToAccept);
	void savePlot();
	vector<Idea> buildPlotIdeas();
	~Repository();
};

