#include "FileStream.h"

void createFile(std::string inputFileName)
{
    std::ofstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Unable to create file." << std::endl;
        return;
    }

    inputFile.close();
}

void fillTextFile(std::string inputFileName)
{
    std::ofstream inputFile;
    inputFile.open(inputFileName, std::ios::app);

    if (!inputFile.is_open()) 
    {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    std::cout << "Enter text (enter 'exit' to complete input):" << std::endl;

    while (std::getline(std::cin, line)) 
    {
        if (line == "exit") 
        {
            break;
        }
        if (!line.empty()) 
        { 
            inputFile << line << std::endl;
        }
    }

    inputFile.close();
}

void processFile(const std::string& inputFileName, const std::string& outputFileName)
{
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;

        if (lineNumber % 2 == 0) {
            if (line.back() == '.') {
                long long dotCount = std::count(line.begin(), line.end(), '.');
                if (dotCount == 1) {
                    continue;
                }
            }

            outputFile << line << '\n';
        }
    }

    inputFile.close();
    outputFile.close();
}

void sortFile(const std::string& outputFileName)
{
    std::ifstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string* lines = new std::string[1000];
    int count = 0;
    while (getline(outputFile, lines[count]))
    {
        count++;
    }
    outputFile.close();

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lines[j] > lines[j + 1]) {
                std::string temp = lines[j];
                lines[j] = lines[j + 1];
                lines[j + 1] = temp;
            }
        }
    }

    std::ofstream outfile(outputFileName);
    for (int i = 0; i < count; i++)
    {
        outfile << lines[i] << std::endl;
    }
    outfile.close();

    delete[] lines;
}

void printFiles(std::string inputFileName, std::string outputFileName)
{
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    std::ifstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        std::cout << "Error opening file!"<< std::endl;
        return;
    }

    std::cout << "Input File:" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Output File:" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    while (std::getline(outputFile, line))
    {
        std::cout << line << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    inputFile.close();
    outputFile.close();
    
}

void appendToFile(const std::string& inputFileName) {
    std::ofstream inputFile(inputFileName, std::ios::app);

    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file\n";
        return;
    }

    std::string line;
    std::cout << "Add text (enter 'exit' to finish input):" << std::endl;

    while (std::getline(std::cin, line)) {
        if (line == "exit") {
            break;
        }
        if (!line.empty()) {
            inputFile << line << std::endl;
        }
    }

    inputFile.close();
}

void AddTextToFile(std::string inputFileName, std::string outputFileName)
{
    char userInput;
    while (true) {
        std::cout << "Add text to the file? (y/n): ";
        std::cin >> userInput;
        if (userInput == 'y') 
        {
            appendToFile(inputFileName);
            processFile(inputFileName, outputFileName);
            sortFile(outputFileName);
            printFiles(inputFileName, outputFileName);   
        }
        else if (userInput == 'n') 
        {
            std::cout << "Bye-bye" << std::endl;
            exit(0);
        }
        else 
        {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    }
}
