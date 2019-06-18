#pragma once
#include "Repository.h"
#include "Observer.h"
class Controller: public Subject
{
private: 
	Repository &repo;
public:
	Controller(Repository &repo):repo(repo),Subject(){}
	vector<Issuee> getIssues() { return repo.getIssue(); }
	vector<Issuee> getIssuesSorted() {
		vector<Issuee> temp = getIssues();
		sort(temp.begin(), temp.end(), [](Issuee i1, Issuee i2) {
			if (i1.getStatus() == i2.getStatus())
				return i1.getDescription() < i2.getDescription();
			return i1.getStatus() < i2.getStatus();
		});
		return temp;
	}
	void addIssue(string description, string reporter) {
		if (description == "")
			throw Exception("Op failed");
		repo.addIssue(Issuee{ description,"open",reporter,"none" });
		notify();
	}
	void removeIssue(Issuee issue) {
		repo.removeIssue(issue);
		notify();
	}
	void solveIssue(Issuee issue,string solver) {
		repo.solveIssue(issue,solver);
		notify();
	}
	~Controller();
};

