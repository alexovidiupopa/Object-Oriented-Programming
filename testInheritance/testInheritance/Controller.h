#pragma once
#include "Repository.h"
#include "UndoOperation.h"
class Controller
{
private:
	Repository repoAll{};
	Repository repoSpecialStorage{};
	std::vector<UndoOperation*> operations;
public:
	Controller();
	void addPainting(std::string artist, std::string title, int year);
	void removePainting(std::string artist, std::string title, int year);
	std::vector<Painting> getAll();
	std::vector<Painting> getSpecialStorage();
	void undo();
	~Controller();
};

