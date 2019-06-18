#pragma once
#include <string>
#include <vector>
#include <iostream>
class Document
{
private: 
	std::string name, keywords, content;

public:
	Document();
	void setName(std::string newName) { name = newName; }
	void setKeywords(std::string newKeywords) { keywords = newKeywords; }
	void setContent(std::string newContent) { content = newContent; }
	std::string getName() { return name; }
	std::string getKeywords() { return keywords; }
	std::string getContent() { return content; }
	std::string toStringNoContent() { return name + " " + keywords; }
	std::string toStringContent() { return name + " " + keywords + " " + content; }
	friend std::istream& operator>>(std::istream &stream, Document &document);
	std::vector<std::string> tokenize(std::string input);
	~Document();
};

