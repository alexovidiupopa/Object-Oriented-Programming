#pragma once

/*THIS CLASS IS NOT USED FOR ANYTHING ANYMORE.*/


template <class GenericElement>
class DynamicVector{
private:
	GenericElement* genericElements;
	int size;
	int capacity;
	void resizeDynamicVector(double factor = 2);

public: 
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& vectorToCopy);
	~DynamicVector();
	GenericElement& operator=(const DynamicVector& vectorToAssign);
	void addToDynamicVector(const GenericElement& genericElementToAdd);
	int getSize() const;
	GenericElement* getAllElements() const;
	void removeFromDynamicVector(int position);
	void updateInDynamicVector(int position, const GenericElement &genericElementToUpdate);
};

template <class GenericElement>
DynamicVector<GenericElement>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->genericElements = new GenericElement[capacity];
}

template <class GenericElement>
DynamicVector<GenericElement>::DynamicVector(const DynamicVector& vectorToCopy) 
{
	this->size = vectorToCopy.size;
	this->capacity = vectorToCopy.capacity;
	this->genericElements = new GenericElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->genericElements[i] = vectorToCopy.genericElements[i];
}

template <class GenericElement>
DynamicVector<GenericElement>::~DynamicVector()
{
	delete[] genericElements;
}

template <class GenericElement>
int DynamicVector<GenericElement>::getSize() const
{
	return this->size;
}

template <class GenericElement>
GenericElement& DynamicVector<GenericElement>::operator=(const DynamicVector& vectorToAssign)
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

template<class GenericElement>
void DynamicVector<GenericElement>::addToDynamicVector(const GenericElement& genericElementToAdd)
{
	if (this->size == this->capacity)
		this->resizeDynamicVector();
	this->genericElements[this->size++] = genericElementToAdd;
}

template<class GenericElement>
void DynamicVector<GenericElement>::removeFromDynamicVector(int position)
{
	this->size--;
	for (int i = position; i < this->size; i++) {
		this->genericElements[i] = this->genericElements[i + 1];
	}
}

template<class GenericElement>
void DynamicVector<GenericElement>::updateInDynamicVector(int position,const GenericElement &genericElementToUpdate)
{
	this->genericElements[position] = genericElementToUpdate;
}

template<class GenericElement>
void DynamicVector<GenericElement>::resizeDynamicVector(double factor)
{
	this->capacity *= static_cast<int>(factor);

	GenericElement* copyElements = new GenericElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		copyElements[i] = this->genericElements[i];

	delete[] this->genericElements;
	this->genericElements = copyElements;
}

template <class GenericElement>
GenericElement* DynamicVector<GenericElement>::getAllElements() const
{
	return this->genericElements;
}