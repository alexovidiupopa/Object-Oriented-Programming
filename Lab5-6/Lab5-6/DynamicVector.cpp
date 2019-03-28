#include "DynamicVector.h"


DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->genericElements = new GenericElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& vectorToCopy)
{
	this->size = vectorToCopy.size;
	this->capacity = vectorToCopy.capacity;
	this->genericElements = new GenericElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->genericElements[i] = vectorToCopy.genericElements[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->genericElements;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& vectorToAssign)
{
	if (this == &vectorToAssign)
		return *this;

	this->size = vectorToAssign.size;
	this->capacity = vectorToAssign.capacity;

	delete[] this->genericElements;
	this->genericElements = new GenericElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->genericElements[i] = vectorToAssign.genericElements[i];

	return *this;
}

void DynamicVector::addToDynamicVector(const GenericElement& genericElementToAdd)
{
	if (this->size == this->capacity)
		this->resizeDynamicVector();
	this->genericElements[this->size++] = genericElementToAdd;
	//this->size++;
}

void DynamicVector::resizeDynamicVector(double factor)
{
	this->capacity *= static_cast<int>(factor);

	GenericElement* copyElements = new GenericElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		copyElements[i] = this->genericElements[i];

	delete[] this->genericElements;
	this->genericElements = copyElements;
}

GenericElement* DynamicVector::getAllElements() const
{
	return this->genericElements;
}

void DynamicVector::removeFromDynamicVector(int position)
{
	this->size--;
	for (int i = position; i < this->size; i++) {
		this->genericElements[i] = this->genericElements[i + 1];
	}
}

void DynamicVector::updateInDynamicVector(int position, const GenericElement & genericElementToUpdate)
{
	this->genericElements[position] = genericElementToUpdate;
}

int DynamicVector::getSize() const
{
	return this->size;
}