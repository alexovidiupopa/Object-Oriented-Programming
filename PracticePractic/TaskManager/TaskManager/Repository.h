#pragma once
#include "Task.h"
#include "Programmer.h"
#include <algorithm>
#include "TaskException.h"
class Repository
{
private:
	void loadProgrammers();
	void loadTasks();
	std::vector<Task> tasks;
	std::vector<Programmer> programmers;
	void saveTasks();
public:
	Repository();
	std::vector<Task> getTasks() { return tasks; }
	std::vector<Programmer> getProgs() { return programmers; }
	void addTask(Task t)
	{
		tasks.push_back(t);
		saveTasks();
	}
	void removeTask(Task t) {
		for (int i = 0; i < tasks.size();i++) {
			if (tasks[i].getDescription() == t.getDescription())
			{
				tasks.erase(tasks.begin()+i);
				break;

			}
		}
		saveTasks();
	}
	void closeTask(Task t){
		for (auto &task : tasks)
			if (task.getDescription() == t.getDescription())
				task.setStatus("closed");
		saveTasks();
	}
	void startTask(Task t,Programmer prog) {
		for (auto& task : tasks) {
			if (task.getDescription() == t.getDescription())
			{
				std::string newStatus= "in progress-working on it is: ";
				newStatus += prog.getName();
				task.setStatus(newStatus);
			}
		}
		saveTasks();
	}
	~Repository();
};

