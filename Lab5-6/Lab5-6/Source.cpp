#include "UI.h"
#include "Tests.h"

int main() {
	runTests();
	Repository repository{};
	Controller controller{repository};
	UI ui{ controller };
	ui.run();
	return 0;
}