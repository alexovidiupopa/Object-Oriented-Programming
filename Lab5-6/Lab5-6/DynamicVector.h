#pragma once
#include "Tape.h"
typedef Tape GenericElement;

class DynamicVector
{
private:
	GenericElement* genericElements;
	int size;
	int capacity;
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resizeDynamicVector(double factor = 2);
public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& vectorToCopy);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& vectorToAssign);

	// Adds an element to the current DynamicVector.
	void addToDynamicVector(const GenericElement& genericElementToAdd);

	int getSize() const;
	GenericElement* getAllElements() const;
	
	void removeFromDynamicVector(int position);

	void updateInDynamicVector(int position, const GenericElement &genericElementToUpdate);

};