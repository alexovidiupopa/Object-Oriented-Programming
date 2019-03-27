#pragma once

typedef void* GenericElement;

class DynamicVector {

private:

	GenericElement* elements;
	int size, capacity;

	void resize();

public:

	DynamicVector();

	void addToVector(GenericElement element);

	void deleteFromVector(GenericElement element,int position);

	void updateInVector(GenericElement element,int position);

	~DynamicVector();
};