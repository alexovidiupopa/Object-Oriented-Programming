#pragma once
#include "RedoOperation.h"
class RedoUpdate :
	public RedoOperation
{
private:
	Repository &tapesRepo;
	Tape tape;
public:
	RedoUpdate(Repository& tapesRepo, Tape tape) :tapesRepo{ tapesRepo }, tape{ tape }, RedoOperation(){}
	void executeRedo()override;
	~RedoUpdate();
};

