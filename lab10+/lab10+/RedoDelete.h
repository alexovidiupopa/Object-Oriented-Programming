#pragma once
#include "RedoOperation.h"
class RedoDelete :
	public RedoOperation
{
private:
	Repository &tapesRepo;
	Tape tape;
public:
	RedoDelete(Repository& tapesRepo, Tape tape) :tapesRepo{ tapesRepo }, tape{ tape }, RedoOperation(){}
	void executeRedo()override;
	~RedoDelete();
};

