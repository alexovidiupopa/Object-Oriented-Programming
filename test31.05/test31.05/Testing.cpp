#include "Testing.h"
#include <assert.h>


Testing::Testing()
{
}


Testing::~Testing()
{
}

void Testing::testBestMatchingFunction()
{
	//test for single match
	assert(testController.getBestMatch("alex").getName() == "alex popa");

	//test for match on multiple entries
	assert(testController.getBestMatch("and").getName() == "andrei mihai");

	//test for match with empty string
	assert(testController.getBestMatch("").getName() == "name surname");
}

void Testing::runTests()
{
	this->testBestMatchingFunction();
}