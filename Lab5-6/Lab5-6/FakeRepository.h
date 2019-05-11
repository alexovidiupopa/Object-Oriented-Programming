#pragma once
#include "FileRepository.h"
class FakeRepository :
	public FileRepository
{
public:
	FakeRepository(std::string path) : FileRepository(path) {};
	~FakeRepository();
};

