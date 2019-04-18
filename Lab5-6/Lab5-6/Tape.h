#pragma once
#include <iostream>
#include <vector>
class Tape {
	
private:

	std::string title, filmedAt, creationDate, footagePreview;
	int accessCount;

public: 
	Tape();
	~Tape();
	Tape( std::string& title, std::string& filmedAt,  std::string& creationDate,  std::string &footagePreview, int accessCount);

	std::string getTitle();

	std::string getFilmedAt();

	std::string getCreationDate();

	std::string getFootagePreview();

	int getAccessCount();

	void setTitle(std::string newTitle);

	void setFilmedAt(std::string filmedAt);

	void setCreationDate(std::string creationDate);

	void setFootagePreview(std::string footagePreview);

	void setAccessCount(int newCount);

	Tape& operator=(const Tape& tapeToCheck);
	bool operator==(const Tape& tapeToCheck);
	//std::vector<std::string> tokenizeInput(std::string inputString, char delimiter);

	friend std::ostream& operator<<(std::ostream &outputStream, const Tape& tapeToPrint);
	
	friend std::istream& operator>>(std::istream &inputStream, Tape& tapeToRead);
	
	
};