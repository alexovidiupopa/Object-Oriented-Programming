#pragma once
#include "Controller.h"
class Testing
{
private:
	void testValidatorsWrongInput();
	void testTapeInputOutputOperators();
	void testCreateTapeAndTapeMethods();
	void testRepositoryAdd();
	void testRepositoryDelete();
	void testRepositoryUpdate();
	void testRepositoryList();
	void testRepository();
	void testAdminModeController();
	void testUserModeController();
	void isolationTestControllerFilter();
public:
	Testing() {};
	void testAll();
	~Testing();
};

