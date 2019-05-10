#pragma once
#include <vector>
#include "Painting.h"
class Repository
{
private:
	std::vector<Painting> paintings;

public:
	Repository() {};
	void addPainting(Painting p);
	void removePainting(Painting p);
	std::vector<Painting> getAll();
	~Repository();
};

