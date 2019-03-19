#pragma once
#include "Profile.h"

typedef void* Telem;
typedef void(*destroyFunction)(Telem);
typedef Telem(*copyFunction)(Telem);

typedef struct
{
	Telem* elements;
	int size, capacity;
	destroyFunction destroyFct;
	copyFunction copyFct;

} DynamicArray;

DynamicArray* createArray(int capacity, destroyFunction destroyF, copyFunction copyF);

void destroyArray(DynamicArray* array);

void addToArray(DynamicArray* array, Telem elementToAdd);

void resize(DynamicArray* array);

DynamicArray* copyArray(DynamicArray* array);