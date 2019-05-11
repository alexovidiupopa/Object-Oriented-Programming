#include "UI.h"
#include "Testing.h"
#include <string>

int main() {
	Testing tests{};
	tests.testAll();
	
	std::string fileLocation, myListLocation;
	
	getline(std::cin, fileLocation);
	fileLocation = fileLocation.substr(13, fileLocation.size() - 11);

	getline(std::cin, myListLocation);
	myListLocation = myListLocation.substr(15, myListLocation.size() - 13);
	
	FileRepository repository{ fileLocation };

	std::string html = "html";
	std::size_t found = myListLocation.find(html);
	if (found!=std::string::npos){
		FilePlaylist* playlist = new HTMLPlaylist{};
		playlist->setFileName(myListLocation);
		Validator validator{};
		Controller controller{ repository,playlist,validator };
		UI ui{ controller };
		ui.run();
		delete playlist;
	}
	else {
		FilePlaylist* playlist = new CSVPlaylist{};
		playlist->setFileName(myListLocation);
		Validator validator{};
		Controller controller{ repository,playlist,validator };
		UI ui{ controller };
		ui.run();
		delete playlist;
	}
	return 0;
}