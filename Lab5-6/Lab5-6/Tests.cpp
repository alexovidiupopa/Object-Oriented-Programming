#include "Tests.h"
#include <assert.h>
#include <fstream>
void testCreate()
{
	//test default tape constructor
	Tape t{};
	
	//test tape creator
	char testTitle[]="F1234", testFilmedAt[] = "restaurant back", testCreationDate[] = "31-03-19", testFootagePreview[] = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt,testCreationDate,testFootagePreview,10);
	Tape testTheSameTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	assert(testTape == testTheSameTape);
	assert(testTape.getAccessCount() == 10);
	testTape.setAccessCount(20);
	assert(testTape.getAccessCount() == 20);
	//strcpy(testCreationDate, "asda");
	testTape.setCreationDate(testCreationDate);
	assert(strcmp(testTape.getCreationDate(), "31-03-19") == 0);
	testTape.setFilmedAt(testFilmedAt);
	//strcpy(testFootagePreview, "abc");
	testTape.setFootagePreview(testFootagePreview);
	assert(strcmp(testTape.getFootagePreview(), "firstTape.mp4") == 0);
	testTape.setTitle(testTitle);
	std::ofstream testOutputStream("test.out");
	testOutputStream << testTape;
}

void testRepo()
{
	Repository testRepository{};
	
	char testTitle[] = "F1234", testFilmedAt[] = "restaurant back", testCreationDate[] = "31-03-19", testFootagePreview[] = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	
	//repository add test
	assert(testRepository.addTapeToRepository(testTape));
	try { 
		assert(testRepository.addTapeToRepository(testTape)); 
    }
	catch (RepositoryException&re) {
		assert(true);
	}
	
	//repository remove test
	assert(testRepository.removeTapeFromRepo(testTape.getTitle()));
	assert(testRepository.addTapeToRepository(testTape));
	
	//repository update test
	strcpy(testFilmedAt, "random place");
	Tape testTape2(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	assert(testRepository.updateTapeInRepo(testTape2));
	
	//repository list test
	std::vector<Tape> testTapesRepository  = testRepository.getAllTapes();
	assert(strcmp(testTapesRepository[0].getFilmedAt(), "random place") == 0);
}

void testAdminModeController()
{
	Repository testRepository{};
	Controller testController{ testRepository };

	//controller add test
	char testTitle[] = "abc", testFilmedAt[] = "here there", testCreationDate[] = "creation date", testFootagePreview[] = "preview.mp4";
	assert(testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10));
	char testTitle2[10] = "abdcefgh", testFilmedAt2[25] = "here there", testCreationDate2[] = "creation date", testFootagePreview2[] = "preview.mp4";
	assert(testController.addTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 11));

	std::vector<Tape> getTestRepository = testController.listTapes();

	//controller remove test
	strcat(testTitle2, "x");
	try {
		assert(testController.removeTape(testTitle2));
	}
	catch (RepositoryException &re) {
		assert(true);
	}
	assert(testController.removeTape(testTitle));

	//controller update test
	strcat(testFilmedAt2, " everywhere");
	strcpy(testTitle2, "abdcefgh");
	assert(testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	strcpy(testTitle2, "abdcefg2h");
	try {
		assert(!testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	}
	catch (RepositoryException &re) {
		assert(true);
	}
}

void testUserModeController()
{
	Repository testRepository{};
	Controller testController{ testRepository };
	
	//test the "next" feature
	char testTitle[10] = "F1234", testFilmedAt[] = "restaurant back", testCreationDate[] = "31-03-19", testFootagePreview[] = "firstTape.mp4";
	testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	testController.initializeIndex();
	Tape nextTape = testController.nextInPlaylist();
	assert(nextTape.getAccessCount() == 10);
	
	//again
	strcpy(testTitle, "F12345");
	testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 11);
	nextTape = testController.nextInPlaylist();
	assert(nextTape.getAccessCount() == 11);

	//strcpy(testTitle, "F1234");
	nextTape = testController.nextInPlaylist();

	//test the "save" + "mylist" features
	assert(testController.saveToPlaylist(testTitle)==true);
	std::vector<Tape>  playlist = testController.listPlaylist();
	//assert(strcmp(playlist, "F12345restaurant back31-03-19 11firstTape.mp4\n") == 0);
	
	//again
	strcpy(testTitle, "F1234");
	assert(testController.saveToPlaylist(testTitle) == true);
	playlist = testController.listPlaylist();
	//assert(strcmp(playlist, "F12345restaurant back31-03-19 11firstTape.mp4\nF1234restaurant back31-03-19 10firstTape.mp4\n") == 0);

	//test for wrong save title
	strcpy(testTitle, "F12");
	try {
		assert(testController.saveToPlaylist(testTitle) == false);
	}
	catch (RepositoryException &re) {
		assert(true);
	}
	//test list filmedAt, accessCount
	std::vector<Tape> specialTestList = testController.listTapesFilmedAtLessThanCount(testFilmedAt, 11);
	//assert(strcmp(specialTestList, "F1234restaurant back31-03-19 10firstTape.mp4\n") == 0);
}
void runTests()
{
	testCreate();
	testRepo();
	testAdminModeController();
	testUserModeController();
}