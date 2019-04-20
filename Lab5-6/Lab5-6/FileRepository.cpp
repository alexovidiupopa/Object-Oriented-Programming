#include "FileRepository.h"
#include <fstream>

void FileRepository::loadRepository()
{
	std::ifstream file(this->path);
	Tape t{};
	while (file >> t) {
		addTapeToRepository(t);
	}
	file.close();
}

void FileRepository::saveRepository()
{
	std::ofstream file(this->path);
	if (!file.is_open())
		return;
	for (auto it : this->getAllTapes()) {
		file << it;
	}
	file.close();
}

FileRepository::~FileRepository()
{
}
