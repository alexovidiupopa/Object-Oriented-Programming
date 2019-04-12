
#include "UI.h"
#include "Tests.h"

int main() {
	testAll();
	Repository repository{};
	repository.moveRobot(Tile{ 1,2 });
	Controller controller{ &repository };
	UI ui{ controller };
	ui.run();
	return 0;
}