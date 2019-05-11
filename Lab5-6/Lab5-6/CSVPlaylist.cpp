#include "CSVPlaylist.h"
#include <fstream>
#include "Exceptions.h"
#include <Windows.h>

void CSVPlaylist::writeToFile()
{
	std::ofstream outFile(this->file);

	if (!outFile.is_open())
		throw FileException("Unable to open file!");
	for (auto tape : this->tapes) {
		outFile << tape;
	}
	outFile.close();
}

void CSVPlaylist::displayPlaylist() const 
{
	std::string path = "\"" + this->file + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\Office16\\EXCEL.EXE", path.c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::vector<Tape> CSVPlaylist::printPlaylistOnScreen() const
{
	return this->tapes;
}
