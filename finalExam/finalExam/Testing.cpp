#include "Testing.h"



void Testing::testAddIdea()
{
	Repository testRepository{ false };
	
	//test to see that the repo is empty
	assert(testRepository.getIdeas().size() == 0);

	testRepository.addIdea(Idea{ "description","proposed","alex","1" });
	
	// test for successful add
	assert(testRepository.getIdeas().size() == 1);
	assert(testRepository.getIdeas()[0].getAct() == "1");

	//test again for successful add
	testRepository.addIdea(Idea{ "description2","accepted","alin","3" });
	assert(testRepository.getIdeas().size() == 2);
	assert(testRepository.getIdeas()[1].getCreator() == "alin");

	//test for unsuccessful add due to the idea already existing
	try {
		testRepository.addIdea(Idea{ "description","accepted","alin","1" });
		assert(false);
	}
	catch (exception &e) {
		assert(strcmp(e.what(), "Already existing idea!")==0);
		assert(true);
	}

}

void Testing::testAcceptIdea()
{
	Repository testRepository{ false };

	//add a dummy idea
	Idea idea{ "description","proposed","alex","3" };
	testRepository.addIdea(idea);

	//accept the same idea
	testRepository.acceptIdea(idea);

	//check if the update was made
	assert(testRepository.getIdeas()[0].getStatus() == "accepted");

	//add another one and test again
	Idea idea2{ "description2","proposed","alin","1" };
	testRepository.addIdea(idea2);

	//test that before the update is made, the idea's status is proposed
	assert(testRepository.getIdeas()[1].getStatus() == "proposed");
	
	//accept it and test that it has now changed to accepted
	testRepository.acceptIdea(idea2);
	assert(testRepository.getIdeas()[1].getStatus() == "accepted");
}

Testing::Testing()
{
	//test the two functionalities
	testAddIdea();
	testAcceptIdea();
}


Testing::~Testing()
{
}
