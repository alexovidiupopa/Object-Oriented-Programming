#include <stdlib.h>

#include "Vector.h"

DynamicArray* createArray(int capacity, destroyFunction destroyFunction, copyFunction copyFunction)
{
	DynamicArray* genericDynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	genericDynamicArray->capacity = capacity;
	genericDynamicArray->size = 0;
	genericDynamicArray->elements = (GenericElement*)malloc(sizeof(GenericElement)*capacity);

	genericDynamicArray->destroyFunction = destroyFunction;
	genericDynamicArray->copyFunction = copyFunction;

	return genericDynamicArray;
}

void destroyArray(DynamicArray* genericDynamicArray)
{
	if (genericDynamicArray == NULL)
		return;

	for (int i = 0; i < genericDynamicArray->size; i++)
	{
		genericDynamicArray->destroyFunction(genericDynamicArray->elements[i]);
		
	}
	free(genericDynamicArray->elements);
	free(genericDynamicArray);
}

void addToArray(DynamicArray * genericDynamicArray, GenericElement elementToAdd)
{
	if (genericDynamicArray->size == genericDynamicArray->capacity)
	{
		resize(genericDynamicArray);
	}
	genericDynamicArray->elements[genericDynamicArray->size++] = genericDynamicArray->copyFunction(elementToAdd);
}

void resize(DynamicArray * genericDynamicArray)
{
	genericDynamicArray->capacity *= 2;
	GenericElement* newElements = (GenericElement*) malloc(sizeof(GenericElement)*genericDynamicArray->capacity);
	for (int i = 0; i < genericDynamicArray->size; i++) {
		newElements[i] = genericDynamicArray->elements[i];
	}
	free(genericDynamicArray->elements);
	genericDynamicArray->elements = newElements;
}

DynamicArray * copyArray(DynamicArray * genericDynamicArray)
{
	DynamicArray* newGenericDynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	newGenericDynamicArray->capacity = genericDynamicArray->capacity;
	newGenericDynamicArray->size = genericDynamicArray->size;
	newGenericDynamicArray->elements = (GenericElement*)malloc(sizeof(GenericElement)*newGenericDynamicArray->capacity);

	newGenericDynamicArray->destroyFunction = genericDynamicArray->destroyFunction;
	newGenericDynamicArray->copyFunction = genericDynamicArray->copyFunction;

	for (int i = 0; i < genericDynamicArray->size; i++)
		newGenericDynamicArray->elements[i] = genericDynamicArray->copyFunction(genericDynamicArray->elements[i]);

	return newGenericDynamicArray;
}
