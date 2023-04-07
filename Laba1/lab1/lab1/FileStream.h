#pragma once
#include <iostream>
#include <fstream>
#include <string>

void createFile(std::string inputFileName);

void fillTextFile(std::string inputFileName);

void processFile(const std::string& inputFileName, const std::string& outputFileName);

void sortFile(const std::string& outputFileName);

void printFiles(std::string inputFileName, std::string outputFileName);

void appendToFile(const std::string& inputFileName);

void AddTextToFile(std::string inputFileName, std::string outputFileName);







