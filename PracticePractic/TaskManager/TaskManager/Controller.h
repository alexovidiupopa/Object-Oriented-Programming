#pragma once
#include "Repository.h"
#include "Observer.h"
#include <algorithm>

class Controller: public Subject
{
private:
	Repository* repo;
public:
	Controller();
	Controller(Repository *repo):repo(repo),Subject(){}
	std::vector<Task> getTasks() { return repo->getTasks(); }
	std::vector<Task> getTasksSorted() {
		std::vector<Task> tasks = getTasks();
		std::sort(tasks.begin(), tasks.end(), [](Task t1, Task t2) {
			return t1.getStatus() < t2.getStatus();
		});
		return tasks;
	}
	void add(std::string desc) {
		Task t{ desc,"open",0 };		
		repo->addTask(t);
		notify();
	}
	void remove(std::string desc) {
		Task t{ desc,"open",0 };
		repo->removeTask(t);
		notify();
	}
	void close(Task t) {
		repo->closeTask(t);
		notify();
	}
	void start(Task t,Programmer prog) {
		if (t.getStatus() != "open")
			throw TaskException("Operation failed!");
		repo->startTask(t,prog);
	}
	~Controller();
};

