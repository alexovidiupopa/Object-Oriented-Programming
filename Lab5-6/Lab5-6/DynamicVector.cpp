#include "DynamicVector.h"

void DynamicVector::resize()
{

}

DynamicVector::DynamicVector()
{
	size = 0;
	capacity = 1;
	elements = new GenericElement[1];
}

void DynamicVector::addToVector(GenericElement element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size++] = element;
}

void DynamicVector::deleteFromVector(GenericElement element,int position)
{
	this->size--;
	for (int i = position; i < this->size; i++) {
		this->elements[i] = this->elements[i + 1];
	}
}

void DynamicVector::updateInVector(GenericElement element,int position)
{
	this->elements[position] = element;
}

DynamicVector::~DynamicVector()
{
	delete[] elements;
}
