#pragma once
#include "Observer.h"
#include "Repository.h"
#include "Exception.h"
class Controller :
	public Subject
{
private:
	Repository &repo;
public:
	Controller();
	Controller(Repository &repo):repo(repo){}
	vector<Question> getQuestionsSorted() { return repo.getQuestionsSorted(); }
	void addQuestion(int id, User user, string text) {
		if (text == "")
			throw Exception("Operation failed.");
		repo.addQuestion(Question{ id,text,user.getName() });
		notify();
	}
	vector<Answer> getAnswersToQuestion(Question q) {
		vector<Answer> answers;
		for (auto ans : repo.getAnswers())
			if (ans.getQuestId() == q.getId())
				answers.push_back(ans);
		return answers;
	}
	void addAnswer(int id, int questId, string answer, string name) {
		if (answer == "")
			throw Exception("Operation failed.");
		repo.addAnswer(Answer{ id,questId,name,answer,0 });
		notify();
		
	}
	Question getBestMatchingQuestion(string text) 
	{
		for (auto quest : repo.getQuestions())
		{
			if (quest.getText().find(text) != string::npos)
				return quest;
		}
		return Question();
	}
	vector<Answer> topThreeAnswers(Question q)
	{
		vector<Answer> sortedAnswers = repo.getAnswers();
		sort(sortedAnswers.begin(),sortedAnswers.end(),[](Answer a1,Answer a2){
			return a1.getVotes() > a2.getVotes(); });
		vector<Answer> result;
		int count = 0;
		for (auto ans : sortedAnswers) {
			if (ans.getQuestId() == q.getId())
			{
				count++;
				result.push_back(ans);
			}
			if (count == 3)
				break;
		}
		return result;
	}
	~Controller();
};

