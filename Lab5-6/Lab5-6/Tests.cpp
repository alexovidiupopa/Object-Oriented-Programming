#include "Tests.h"
#include <assert.h>
#include <iostream>
void testCreate()
{
	//test tape creator
	char testTitle[]="F1234", testFilmedAt[] = "restaurant back", testCreationDate[] = "31-03-19", testFootagePreview[] = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt,testCreationDate,testFootagePreview,10);
	assert(testTape.getAccessCount() == 10);
	testTape.setAccessCount(20);
	assert(testTape.getAccessCount() == 20);
}

void testRepo()
{
	Repository testRepository{};
	
	char testTitle[] = "F1234", testFilmedAt[] = "restaurant back", testCreationDate[] = "31-03-19", testFootagePreview[] = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	
	//repository add test
	assert(testRepository.addTapeToRepository(testTape));
	assert(!testRepository.addTapeToRepository(testTape));
	
	//repository remove test
	assert(testRepository.removeTapeFromRepo(testTape.getTitle()));
	assert(testRepository.addTapeToRepository(testTape));
	
	//repository update test
	strcpy(testFilmedAt, "random place");
	Tape testTape2(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	assert(testRepository.updateTapeInRepo(testTape2));
	
	//repository list test
	DynamicVector<Tape> testTapesRepository  = testRepository.getAllTapes();
	Tape* testTapes = testTapesRepository.getAllElements();
	assert(strcmp(testTapes[0].getFilmedAt(), "random place") == 0);
}

void testAdminModeController()
{
	Repository testRepository{};
	Controller testController{ testRepository };
	
	//controller add test
	char testTitle[] = "abc", testFilmedAt[] = "here there", testCreationDate[] = "creation date", testFootagePreview[] = "preview.mp4";
	assert(testController.addTape(testTitle, testFilmedAt,testCreationDate,testFootagePreview,10));
	char testTitle2[10] = "abdcefgh", testFilmedAt2[25] = "here there", testCreationDate2[] = "creation date", testFootagePreview2[] = "preview.mp4";
	assert(testController.addTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 11));
	
	//controller remove test
	strcat(testTitle2, "x");
	assert(!testController.removeTape(testTitle2));
	assert(testController.removeTape(testTitle));
	
	//controller update test
	strcat(testFilmedAt2, " everywhere");
	strcpy(testTitle2, "abdcefgh");
	assert(testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	strcpy(testTitle2, "abdcefg2h");
	assert(!testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
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
	
	//test the "save" + "mylist" features
	assert(testController.saveToPlaylist(testTitle)==true);
	char playlist[1001];
	playlist[0] = 0;
	testController.listPlaylist(playlist);
	assert(strcmp(playlist, "F12345restaurant back31-03-19 11firstTape.mp4\n") == 0);
	
	//again
	strcpy(testTitle, "F1234");
	assert(testController.saveToPlaylist(testTitle) == true);
	playlist[0] = 0;
	testController.listPlaylist(playlist);
	assert(strcmp(playlist, "F12345restaurant back31-03-19 11firstTape.mp4\nF1234restaurant back31-03-19 10firstTape.mp4\n") == 0);

	//test for wrong save title
	strcpy(testTitle, "F12");
	assert(testController.saveToPlaylist(testTitle) == false);

	//test list filmedAt, accessCount
	char specialTestList[1001];
	specialTestList[0] = 0;
	testController.listTapesFilmedAtLessThanCount(specialTestList, testFilmedAt, 11);
	assert(strcmp(specialTestList, "F1234restaurant back31-03-19 10firstTape.mp4\n") == 0);
}
void runTests()
{
	testCreate();
	testRepo();
	testAdminModeController();
	testUserModeController();
}