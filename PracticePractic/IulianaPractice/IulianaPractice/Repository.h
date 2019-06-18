#pragma once
#include "Issuee.h"
#include "User.h"
#include "Exception.h"
class Repository
{
private:
	vector<Issuee> issues;
	vector<User> users;
	void loadUsers() {
		ifstream f("users.txt");
		User u{};
		while (f >> u)
			users.push_back(u);
		f.close();
	}
	void loadIssues() {
		ifstream f("issues.txt");
		Issuee i{};
		while (f >> i)
			issues.push_back(i);
		f.close();
	}
	void saveIssues() {
		ofstream g("issues.txt");
		for (auto iss : getIssue()) {
			g << iss.toString();
		}
		g.close();
	}
public:
	Repository();
	vector<User> getUsers() { return users; }
	vector<Issuee> getIssue() { return issues; }
	void addIssue(Issuee i) {
		for (auto iss : issues)
			if (iss.getDescription() == i.getDescription())
				throw Exception("op failed.");
		issues.push_back(i);
		saveIssues();
	}
	void removeIssue(Issuee issue) {
		for(int i=0;i<issues.size();i++)
			if (issues[i].getDescription() == issue.getDescription()) {
				issues.erase(issues.begin() + i);
				break;
			}
		saveIssues();
	}
	void solveIssue(Issuee issue,string solver) {
		for (auto &iss : issues)
			if (iss.getDescription() == issue.getDescription())
			{
				iss.setStatus("closed");
				iss.setSolver(solver);
			}
		saveIssues();
		
	
	}
	~Repository();
};

