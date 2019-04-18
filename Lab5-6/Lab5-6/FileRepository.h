#pragma once
#include "Repository.h"
class FileRepository :
	public Repository
{
private:
	std::string path="";
	std::vector<Tape> tapes;
public:
	FileRepository() {};
	
	void loadRepository();
	void saveRepository();
	void setPath(std::string path) { this->path = path; };
	~FileRepository();



};
