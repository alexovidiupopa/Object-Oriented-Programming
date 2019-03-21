#pragma once
#include "Profile.h"

typedef void* GenericElement;
typedef void(*destroyFunction)(GenericElement);
typedef GenericElement(*copyFunction)(GenericElement);

typedef struct
{
	GenericElement* elements;
	int size, capacity;
	destroyFunction destroyFunction;
	copyFunction copyFunction;

} DynamicArray;

DynamicArray* createArray(int capacity, destroyFunction destroyFunction, copyFunction copyFunction);

void destroyArray(DynamicArray* genericDynamicArray);

void addToArray(DynamicArray* genericDynamicArray, GenericElement elementToAdd);

void resize(DynamicArray* genericDynamicArray);

DynamicArray* copyArray(DynamicArray* genericDynamicArray);