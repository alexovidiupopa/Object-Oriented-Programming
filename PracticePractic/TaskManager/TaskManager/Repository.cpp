#include "Repository.h"

#include <fstream>

void Repository::loadProgrammers()
{
	std::ifstream f("prog.txt");
	Programmer p{};
	while (f >> p) {
		programmers.push_back(p);
	}
	f.close();
}

void Repository::loadTasks()
{
	std::ifstream f("tasks.txt");
	Task t{};
	while (f >> t) {
		tasks.push_back(t);
	}
	f.close();
}

void Repository::saveTasks()
{
	std::ofstream g("tasks.txt");
	for (auto t : tasks) {
		g << t.toString();
	}
	g.close();
}

Repository::Repository()
{
	loadProgrammers();
	loadTasks();
}


Repository::~Repository()
{
}
