#pragma once
#include "Tape.h"
typedef Tape GenericElement;

class DynamicVector
{
private:
	GenericElement* genericElements;
	int size;
	int capacity;
	
	void resizeDynamicVector(double factor = 2);
public:
	
	DynamicVector(int capacity = 10);

	
	DynamicVector(const DynamicVector& vectorToCopy);
	~DynamicVector();

	
	DynamicVector& operator=(const DynamicVector& vectorToAssign);

	
	void addToDynamicVector(const GenericElement& genericElementToAdd);

	int getSize() const;
	GenericElement* getAllElements() const;
	
	void removeFromDynamicVector(int position);

	void updateInDynamicVector(int position, const GenericElement &genericElementToUpdate);

};