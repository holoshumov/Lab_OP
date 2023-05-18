#pragma once
#include"TArray.h"
#include "IntArray.h"
#include "DoubleArray.h"
using namespace std;

void createArrays(intArray**& intArrays, DoubleArray**& doubleArrays, int m);
void printArrays(intArray** intArrays, DoubleArray** doubleArrays, int m);
void modifyArrays(intArray** intArrays, DoubleArray** doubleArrays, int m, int value);
void findMaxAverageArray(intArray** intArrays, DoubleArray** doubleArrays, int m);
void freeMemory(intArray** intArrays, DoubleArray** doubleArrays, int m);

