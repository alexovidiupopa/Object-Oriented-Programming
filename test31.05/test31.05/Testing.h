#pragma once
#include "Controller.h"
class Testing
{
private:
	Controller testController{};
	void testBestMatchingFunction();
public:
	Testing();
	void runTests();
	~Testing();
};

