#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

void createFile(const char* inputFileName);

void fillTextFile(const char* inputFileName);

void processFile(const char* inputFileName, const char* outputFileName);

void sortFile(const char* outputFileName);

void printFiles(const char* inputFileName, const char* outputFileName);

void appendToFile(const char* inputFileName);

void addTextToFile(const char* inputFileName, const char* outputFileName);