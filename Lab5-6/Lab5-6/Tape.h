#pragma once
#include <cstring>
class Tape {
	
private:

	char title[21], filmedAt[41], creationDate[41], footagePreview[21];
	int accessCount;

public: 
	Tape();

	Tape(char title[], char filmedAt[], char creationDate[], char footagePreview[], int accessCount);

	char* getTitle();

	const char* getFilmedAt();

	const char* getCreationDate();

	const char* getFootagePreview();

	int getAccessCount();

	void setTitle(char newTitle[]);

	void setFilmedAt(char filmedAt[]);

	void setCreationDate(char creationDate[]);

	void setFootagePreview(char footagePreview[]);

	void setAccessCount(int newCount);

	Tape& operator=(const Tape& tapeToCheck);
	bool operator==(const Tape& tapeToCheck);

	~Tape();
};