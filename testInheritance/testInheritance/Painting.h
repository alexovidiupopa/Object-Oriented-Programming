#pragma once
#include <string>
class Painting
{
private: 
	std::string title, artist;
	int year;
public:
	Painting(std::string title, std::string artist, int year) :title{ title }, artist{ artist }, year{ year } {};
	std::string getTitle();
	std::string getArtist();
	int getYear();
	~Painting();
};

