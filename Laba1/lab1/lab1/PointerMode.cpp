#include <iostream>
#include "PointerMode.h"


void FilePointer()
{
	std::cout << " ---FilePointer mode---" << std::endl;

	const char* inputFileName = "input.txt";
	const char* outputFileName = "output.txt";

	createFile(inputFileName);
	fillTextFile(inputFileName);
	processFile(inputFileName, outputFileName);
	sortFile(outputFileName);
	printFiles(inputFileName, outputFileName);
	addTextToFile(inputFileName, outputFileName);
}
	

