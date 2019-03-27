#include <iostream>
#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>


using namespace std;

int main() {
	/*testCreate();
	cout << "a"<<endl;
	testRepo();
	cout << "b" << endl;*/
	Repository* repository = new Repository();
	Validator* validator = new Validator();
	Controller* controller = new Controller(repository,validator);
	UI* ui = new UI(controller);
	ui->run();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}