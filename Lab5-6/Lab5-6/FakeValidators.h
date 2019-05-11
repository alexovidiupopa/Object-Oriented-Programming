#pragma once
#include "Validator.h"
class FakeValidators :
	public Validator
{
public:
	FakeValidators() : Validator() {};
	~FakeValidators();
};

