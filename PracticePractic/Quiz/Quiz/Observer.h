#pragma once
#include <vector>
#include <algorithm>
class Observer
{
public:
	Observer();
	~Observer();
	virtual void update() = 0;
};

class Subject
{
private:
	std::vector<Observer*> observers;
public:
	Subject();
	void registerObserver(Observer *obs) {
		observers.push_back(obs);
	}
	void unregisterObserver(Observer *obs) {
		observers.erase(std::find(observers.begin(), observers.end(), obs));
	}
	void notify() {
		for (auto o : observers) {
			o->update();
		}
	}
	~Subject();
};

