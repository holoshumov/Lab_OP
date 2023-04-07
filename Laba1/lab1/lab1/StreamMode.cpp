#include "FileStream.h"

void  FileStream()
{
    std::cout << " ----FileStream mode---" << std::endl;

    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    createFile(inputFileName);
    fillTextFile(inputFileName);
    processFile(inputFileName, outputFileName);
    sortFile(outputFileName);
    printFiles(inputFileName, outputFileName);
    AddTextToFile(inputFileName, outputFileName);
}
