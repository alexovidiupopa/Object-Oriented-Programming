#pragma once
#include <vector>
#include <algorithm>
class Observer
{
public:
	Observer();
	virtual void update() = 0;
	~Observer();
};

class Subject
{
private:
	std::vector<Observer*> observers;
public:
	Subject();
	void registerObserver(Observer* obs) { observers.push_back(obs); }
	void unregisterObserver(Observer* obs) { observers.erase(std::find(observers.begin(),observers.end(),obs)); }
	void notify() {
		for (auto obs : observers) {
			obs->update();
		}
	}
	~Subject();
};

