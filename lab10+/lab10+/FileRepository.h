#pragma once
#include "Repository.h"
class FileRepository :
	public Repository
{
private:
	std::string path="";
	std::vector<Tape> tapes;
public:
	FileRepository(std::string path) ;
	
	void loadRepository() override;
	void saveRepository() override;
	void setPath(std::string path) override { this->path = path; };
	~FileRepository();



};

