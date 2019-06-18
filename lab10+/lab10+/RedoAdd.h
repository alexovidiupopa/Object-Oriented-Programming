#pragma once
#include "RedoOperation.h"
class RedoAdd :
	public RedoOperation
{
private: 
	Repository &tapesRepo;
	Tape tape;
public:
	RedoAdd(Repository& tapesRepo, Tape tape) :tapesRepo{ tapesRepo }, tape{ tape }, RedoOperation(){}
	void executeRedo()override;
	~RedoAdd();
};

