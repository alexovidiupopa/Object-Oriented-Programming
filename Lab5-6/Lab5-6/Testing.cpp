#include "Testing.h"
#include <assert.h>
#include <fstream>
#include "FakeRepository.h"
#include "FakeValidators.h"
#include "FakePlaylist.h"


void Testing::testCreateTapeAndTapeMethods()
{
	Tape defaultTape{};
	
	//test tape creator
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt,testCreationDate,testFootagePreview,10);
	Tape testTheSameTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	
	// "==" operator
	assert(testTape == testTheSameTape);
	
	assert(testTape.getAccessCount() == 10);
	testTape.setAccessCount(20);
	assert(testTape.getAccessCount() == 20);
	testTape.setCreationDate(testCreationDate);
	assert(testTape.getCreationDate()=="31-03-19");
	testTape.setFilmedAt(testFilmedAt);
	testTape.setFootagePreview(testFootagePreview);
	assert(testTape.getFootagePreview()== "firstTape.mp4");
	testTape.setTitle(testTitle);
}

void Testing::testTapeInputOutputOperators()
{
	Tape testTape{};
	std::ifstream testInputStream("test.in");
	testInputStream >> testTape;
	std::ofstream testOutputStream("test.out");
	testOutputStream << testTape;
}

void Testing::testValidatorsWrongInput()
{
	Validator testValidator;
	try {
		testValidator.validateData("", "", "", "", -1);
	}
	catch (ValidatorException &exception) {

	}
}

void Testing::testRepositoryAdd()
{
	Repository testRepository{};
		
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	
	(testRepository.addTapeToRepository(testTape));
	try { 
		(testRepository.addTapeToRepository(testTape)); 
	}
	catch (RepositoryException&re) {
		assert(true);
	}
}

void Testing::testRepositoryDelete()
{
	Repository testRepository{};
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	(testRepository.addTapeToRepository(testTape));
	(testRepository.removeTapeFromRepo(testTape.getTitle()));
	(testRepository.addTapeToRepository(testTape));
}

void Testing::testRepositoryUpdate()
{
	Repository testRepository{};
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	(testRepository.addTapeToRepository(testTape));
	testFilmedAt = "random place";
	Tape testTape2(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	testRepository.updateTapeInRepo(testTape2);
}

void Testing::testRepositoryList()
{
	Repository testRepository{};
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview = "firstTape.mp4";
	Tape testTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	(testRepository.addTapeToRepository(testTape));
	std::vector<Tape> testTapesRepository = testRepository.getAllTapes();
	assert(testTapesRepository[0].getFilmedAt()=="restaurant back");
}

void Testing::testRepository()
{
	testRepositoryAdd();
	testRepositoryDelete();
	testRepositoryUpdate();
	testRepositoryList();
}

void Testing::testAdminModeController()
{
	FileRepository testRepository{"testRepo.txt"};
	FilePlaylist *testPlaylist = new CSVPlaylist{};
	Validator testValidator{};
	
	Controller testController{ testRepository,testPlaylist, testValidator };
	std::string testTitle = "abcd", testFilmedAt = "here there", testCreationDate = "creation date", testFootagePreview = "preview.mp4";
	//(testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10));
	std::string testTitle2 = "abcdefgh", testFilmedAt2 = "here there", testCreationDate2 = "creation date", testFootagePreview2 = "preview.mp4";
	//(testController.addTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 11));
	std::vector<Tape> getTestRepository = testController.listTapes();
	
	testTitle2 += "x";
	try {
		(testController.removeTape(testTitle2));
	}
	catch (RepositoryException &re) {
		assert(re.getMessage() == "Tape doesn't exist");
	}
	try {
		(testController.removeTape(testTitle));
	}
	catch (RepositoryException &re) {

	}
	testTitle2 = "abcdefgh";
	(testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	
	//test for wrong input
	testTitle2 = "abdcefg2h";
	try {
		(testController.updateTape(testTitle2, testFilmedAt2, testCreationDate2, testFootagePreview2, 12));
	}
	catch (RepositoryException &re) {
		assert(true);
	}
}

void Testing::testUserModeController()
{
	FileRepository testRepository{ "testRepoFile.txt" };
	FilePlaylist *testPlaylist = new CSVPlaylist{};
	testPlaylist->setFileName("test.csv");
	Validator testValidator;
	Controller testController{ testRepository,testPlaylist, testValidator };
	
	std::string testTitle = "F1234", testFilmedAt = "restaurant back", testCreationDate = "31-03-19", testFootagePreview= "firstTape.mp4";
	//testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 10);
	testController.initializeIndex();
	Tape nextTape = testController.nextInPlaylist();
	assert(nextTape.getAccessCount() == 10);
	
	//again
	//testTitle = "F12345";
	//testController.addTape(testTitle, testFilmedAt, testCreationDate, testFootagePreview, 11);
	nextTape = testController.nextInPlaylist();
	assert(nextTape.getAccessCount() == 11);

	
	nextTape = testController.nextInPlaylist();

	//test the "save" + "mylist" features
	(testController.saveToPlaylist(testTitle));
	std::vector<Tape>  playlist = testController.listPlaylist();
	assert(playlist[0].getAccessCount() == 10);
	
	
	//again
	testTitle = "F1234";
	(testController.saveToPlaylist(testTitle)  );
	playlist = testController.listPlaylist();
	assert(playlist[1].getAccessCount() == 10);

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
	assert(specialTestList[0].getAccessCount() == 10);
}

void Testing::isolationTestControllerFilter()
{
	FakeRepository fakeRepository{"fakerepo.txt"};
	FilePlaylist *fakePlaylist = new FakePlaylist{};
	FakeValidators fakeValidators{};
	Controller testController{ fakeRepository,fakePlaylist,fakeValidators };
	std::vector<Tape> testOutput =  testController.listTapesFilmedAtLessThanCount(" home", 12);
	assert(testOutput[0].getTitle() == "abcd");
	assert(testOutput[1].getTitle() == "defg");
	assert(testOutput.size() == 2);
}

void Testing::testAll()
{
	testCreateTapeAndTapeMethods();
	testTapeInputOutputOperators();
	testValidatorsWrongInput();
	testRepository();
	testAdminModeController();
	testUserModeController();
	isolationTestControllerFilter();
}


Testing::~Testing()
{
}
