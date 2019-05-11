#include "HTMLPlaylist.h"
#include <Windows.h>
#include <fstream>
#include "Exceptions.h"
using namespace std;
void HTMLPlaylist::writeToFile()
{
	ofstream outFile(this->file);
	if (!outFile.is_open())
		throw FileException("Unable to open file!");
	outFile << "<!DOCTYPE html>" << endl;
	outFile << "<html>" << endl;
	outFile << "<head><title>Playlist</title></head>" << endl;
	outFile << "<body style=\"background-color:powderblue;\"><table border=\"1\">" << endl;

	outFile << "<tr>" << endl;
	outFile << "<td>Title</td>" << endl;
	outFile << "<td>Filmed At</td>" << endl;
	outFile << "<td>Creation Date</td>" << endl;
	outFile << "<td>Access Count</td>" << endl;
	outFile << "<td>Footage Preview</td>" << endl;
	outFile << "</tr>" << endl;	
	for (auto tape : this->tapes) {
		outFile << "<tr>" << endl;
		outFile << "<td>" << tape.getTitle() << "</td>" << endl;
		outFile << "<td>" << tape.getFilmedAt() << "</td>" << endl;
		outFile << "<td>" << tape.getCreationDate() << "</td>" << endl;
		outFile << "<td>" << tape.getAccessCount() << "</td>" << endl;
		outFile << "<td>" << tape.getFootagePreview() << "</td>" << endl;
		outFile << "</tr>" << endl;
	}
	outFile << "</table>" << endl;
	outFile << "</body>" << endl;
	outFile << "</html>" << endl;
	outFile.close();
}

void HTMLPlaylist::displayPlaylist() const
{
	std::string path = "\"" + this->file + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Mozilla Firefox\\firefox.exe", path.c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::vector<Tape> HTMLPlaylist::printPlaylistOnScreen() const
{
	return this->tapes;
}
