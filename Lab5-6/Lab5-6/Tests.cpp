#include "Tests.h"
#include <assert.h>
#include <fstream>
void testCreate()
{
	//test default tape constructor
	Tape t{};
	
	//test tape creator
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt,testCreationDate,testFootagePreview,10);
	Tape testTheSameTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	assert(testTape == testTheSameTape);
	assert(testTape.getAccessCount() == 10);
	testTape.setAccessCount(20);
	assert(testTape.getAccessCount() == 20);
	//strcpy(testCreationDate, "asda");
	testTape.setCreationDate(testCreationDate);
	assert(testTape.getCreationDate()=="31-03-19");
	testTape.setFilmedAt(testFilmedAt);
	//strcpy(testFootagePreview, "abc");
	testTape.setFootagePreview(testFootagePreview);
	assert(testTape.getFootagePreview()== "firstTape.mp4");
	testTape.setTitle(testTitle);
	std::ifstream testInputStream("test.in");
	std::ofstream testOutputStream("test.out");
	testOutputStream << testTape;
}

void testRepo()
{
	Repository testRepository{};
	
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	
	//repository add test
	(testRepository.addTapeToRepository(testTape));
	try { 
		(testRepository.addTapeToRepository(testTape)); 
    }
	catch (RepositoryException&re) {
		assert(true);
	}
	
	//repository remove test
	(testRepository.removeTapeFromRepo(testTape.getTitle()));
	(testRepository.addTapeToRepository(testTape));
	
	//repository update test
	testFilmedAt = "random place";
	Tape testTape2(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	(testRepository.updateTapeInRepo(testTape2));
	
	//repository list test
	std::vector<Tape> testTapesRepository  = testRepository.getAllTapes();
	assert(testTapesRepository[0].getFilmedAt()=="random place");
}

void testAdminModeController()
{
	FileRepository testRepository{};
	Controller testController{ testRepository };

	//controller add test
	std::string testTitle = "abc", testFilmedAt = "here there", testCreationDate = "creation date", testFootagePreview = "preview.mp4";
	(testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10));
	std::string testTitle2 = "abdcefgh", testFilmedAt2 = "here there", testCreationDate2 = "creation date", testFootagePreview2 = "preview.mp4";
	(testController.addTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 11));

	std::vector<Tape> getTestRepository = testController.listTapes();

	//controller remove test
	testTitle2 += "x";
	try {
		(testController.removeTape(testTitle2));
	}
	catch (RepositoryException &re) {
		assert(re.getMessage() == "Tape doesn't exist");
	}
	(testController.removeTape(testTitle));

	//controller update test
	testTitle2 += "everywhere";
	testTitle2 = "abdcefgh";
	(testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	testTitle2 = "abdcefg2h";
	try {
		(testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	}
	catch (RepositoryException &re) {
		assert(true);
	}
}

void testUserModeController()
{
	FileRepository testRepository{};
	Controller testController{ testRepository };
	
	//test the "next" feature
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview= "firstTape.mp4";
	testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	testController.initializeIndex();
	Tape nextTape = testController.nextInPlaylist();
	assert(nextTape.getAccessCount() == 10);
	
	//again
	testTitle = "F12345";
	testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 11);
	nextTape = testController.nextInPlaylist();
	assert(nextTape.getAccessCount() == 11);

	//strcpy(testTitle, "F1234");
	nextTape = testController.nextInPlaylist();

	//test the "save" + "mylist" features
	(testController.saveToPlaylist(testTitle));
	std::vector<Tape>  playlist = testController.listPlaylist();
	//assert(strcmp(playlist, "F12345restaurant back31-03-19 11firstTape.mp4\n") == 0);
	
	//again
	testTitle = "F1234";
	(testController.saveToPlaylist(testTitle)  );
	playlist = testController.listPlaylist();
	//assert(strcmp(playlist, "F12345restaurant back31-03-19 11firstTape.mp4\nF1234restaurant back31-03-19 10firstTape.mp4\n") == 0);

	//test for wrong save title
	testTitle = "F12";
	try {
		(testController.saveToPlaylist(testTitle) );
	}
	catch (RepositoryException &re) {
		assert(true);
	}
	//test list filmedAt, accessCount
	std::vector<Tape> specialTestList = testController.listTapesFilmedAtLessThanCount(testFilmedAt, 11);
	//assert(strcmp(specialTestList, "F1234restaurant back31-03-19 10firstTape.mp4\n") == 0);
}

void testFileRepo()
{
	FileRepository testRepository{};
	Controller testController{ testRepository };
	testController.setRepository("testRepo.txt");
	std::vector<Tape> getTestRepository = testController.listTapes();
	assert(getTestRepository[0].getTitle() == "testTitle");
	std::string testTitle = "F1234", testFilmedAt = " restaurant back", testCreationDate = " 31-03-19", testFootagePreview = " firstTape.mp4";
	testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	std::vector<Tape> getTestRepository2 = testController.listTapes();
	assert(getTestRepository2[1].getTitle() == "F1234");
	testController.removeTape(testTitle);
	
}
void runTests()
{
	testCreate();
	testRepo();
	testAdminModeController();
	testUserModeController();
	testFileRepo();
}