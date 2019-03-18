#include <stdlib.h>

#include "Vector.h"

DynamicArray* createArray(int capacity, destroyFunction destroyF, copyFunction copyF)
{
	DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
	array->capacity = capacity;
	array->size = 0;
	array->elements = (Telem*)malloc(sizeof(Telem)*capacity);

	array->destroyFct = destroyF;
	array->copyFct = copyF;

	return array;
}

void destroyArray(DynamicArray* array)
{
	if (array == NULL)
		return;

	for (int i = 0; i < array->size; i++)
		array->destroyFct(array->elements[i]);

	free(array->elements);
	free(array);
}

int addToArray(DynamicArray * array, Telem elementToAdd)
{
	if (array->size == array->capacity)
	{
		resize(array);
	}
	array->elements[array->size++] = array->copyFct(elementToAdd);
	return 1;
}

void resize(DynamicArray * array)
{
	array->capacity *= 2;
	Telem* newElems = malloc(sizeof(Telem)*array->capacity);
	for (int i = 0; i < array->size; i++) {
		newElems[i] = array->elements[i];
	}
	free(array->elements);
	array->elements = newElems;
}

DynamicArray * copyArray(DynamicArray * array)
{
	DynamicArray* newA = (DynamicArray*)malloc(sizeof(DynamicArray));
	newA->capacity = array->capacity;
	newA->size = array->size;
	newA->elements = (Telem*)malloc(sizeof(Telem)*newA->capacity);

	newA->destroyFct = array->destroyFct;
	newA->copyFct = array->copyFct;

	for (int i = 0; i < array->size; i++)
		newA->elements[i] = array->copyFct(array->elements[i]);

	return newA;
}
