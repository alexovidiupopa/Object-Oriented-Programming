#pragma once
#include "Utils.h"
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
	vector<Observer*> observers;
public:
	Subject();
	void registerObs(Observer* obs) { observers.push_back(obs); }
	void notify() {
		for (auto obs : observers)
			obs->update();
	}
	~Subject();
};

