#include "UI.h"
#include <Windows.h>
#include "Tests.h"

int main() {
	runTests();
	Repository repository{};
	Validator validator ();
	Controller controller{repository};
	UI ui{ controller };
	ui.run();
	system("pause");
	return 0;
}