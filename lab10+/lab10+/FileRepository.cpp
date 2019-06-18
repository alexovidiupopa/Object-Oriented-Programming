#include "FileRepository.h"
#include <fstream>

FileRepository::FileRepository(std::string path) : Repository{}
{
	this->path = path;
	loadRepository();
}

void FileRepository::loadRepository()
{
	std::ifstream file(this->path);
	Tape tape{};
	while (file >> tape) {
		addTapeToRepository(tape);
	}
	file.close();
}

void FileRepository::saveRepository()
{
	std::ofstream outFile(this->path);
	if (!outFile.is_open())
		return;
	for (auto tape : this->getAllTapes()) {
		outFile << tape;
	}
	outFile.close();
}

FileRepository::~FileRepository()
{
}
