#include "FilePointer.h"

void createFile(const char* inputFileName)
{
    FILE* inputFile;

    inputFile = fopen(inputFileName, "w");
    if (inputFile == NULL)
    {
        printf("Unable to create file.");
        return;
    }

    fclose(inputFile);
}

void fillTextFile(const char* filename)
{
    FILE* file = fopen(filename, "a");
    if (file != NULL)
    {
        char buffer[1000];
        std::cout << "Enter text (enter 'exit' to complete the input): " << std::endl;
        while (true)
        {
            std::cin.getline(buffer, sizeof(buffer));
            if (std::strcmp(buffer, "exit") == 0)
            {
                break;
            }
            std::fputs(buffer, file);
            if (std::strcmp(buffer, "") != 0) 
            {
                std::fputs("\n", file);
            }
        }
        std::fclose(file);
    }
    else
    {
        std::cout << "Error opening file!" << std::endl;
    }
}


void processFile(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");

    char line[256];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), inputFile) != nullptr)
    {
        lineNumber++;

        if (lineNumber % 2 == 0)
        {
            if (line[strlen(line) - 2] == '.')
            {
                long long dotCount = std::count(line, line + strlen(line), '.');
                if (dotCount == 1)
                {
                    continue;
                }
            }

            fputs(line, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

void sortFile(const char* outputFileName)
{
    FILE* outputFile = fopen(outputFileName, "r");
    if (outputFile == NULL)
    {
        std::cerr << "Error opening file!" << outputFileName << std::endl;
        return;
    }

    char** lines = (char**)malloc(sizeof(char*) * 1000);
    if (lines == NULL)
    {
        std::cerr << "Error: could not allocate memory for lines" << std::endl;
        fclose(outputFile);
        return;
    }

    for (int i = 0; i < 1000; i++)
    {
        lines[i] = (char*)malloc(sizeof(char) * 1000);
        if (lines[i] == NULL)
        {
            std::cerr << "Error: could not allocate memory for line " << i << std::endl;
            for (int j = 0; j < i; j++)
            {
                free(lines[j]);
            }
            free(lines);
            fclose(outputFile);
            return;
        }
    }

    int count = 0;
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), outputFile))
    {
        if (count < 1000)
        {
            strcpy(lines[count], buffer);
            count++;
        }
        else
        {
            std::cerr << "Error: too many lines in file" << std::endl;
            break;
        }
    }
    fclose(outputFile);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (lines[i] != NULL && lines[j] != NULL && strcmp(lines[i], lines[j]) > 0)
            {
                char tmp[1000];
                strcpy(tmp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], tmp);
            }
        }
    }

    FILE* outputFilename = fopen(outputFileName, "w");
    if (outputFilename == NULL)
    {
        std::cerr << "Error opening file!" << outputFileName << std::endl;
        for (int i = 0; i < count; i++)
        {
            free(lines[i]);
        }
        free(lines);
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (lines[i] != NULL)
        {
            fprintf(outputFilename, "%s", lines[i]);
        }
    }
    fclose(outputFilename);

    for (int i = 0; i < 1000; i++)
    {
        free(lines[i]);
    }
    free(lines);
}

void printFiles(const char* inputFileName, const char* outputFileName)
{
    FILE* inputFile = fopen(inputFileName, "r"); 

    if (inputFile == NULL)
    {
        std::cerr << "Error opening file!" << inputFile << std::endl;
        return;
    }

    FILE* outputFile = fopen(outputFileName, "r");

    if (inputFile == NULL)
    { 
        std::cerr << "Error opening file!" << outputFile << std::endl;
        return;
    }

    std::cout << "Input File" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    int r1;
    while ((r1 = fgetc(inputFile)) != EOF) 
    {
        putchar(r1);
    }
    std::cout << "--------------------------------------------------------------" << std::endl;

    std::cout << "\nOutput File" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    int r2;
    while ((r2 = fgetc(outputFile)) != EOF) 
    {
        putchar(r2); 
    }
    std::cout << "--------------------------------------------------------------" << std::endl;

    fclose(inputFile);
    fclose(outputFile);
}

void appendToFile(const char* inputFileName) 
{
    FILE* file = fopen(inputFileName, "a");
    if (file != NULL) 
    {
        char buffer[1000];
        std::cout << "Enter text to append (enter 'exit' to complete the input): " << std::endl;
        while (true) 
        {
            std::cin.getline(buffer, sizeof(buffer));
            if (std::strcmp(buffer, "exit") == 0) 
            {
                break;
            }
            std::fputs(buffer, file);
            if (std::strcmp(buffer, "") != 0) 
            { 
                std::fputs("\n", file);
            }
        }
        std::fclose(file);
    }
    else 
    {
        std::cout << "Error opening file!" << std::endl;
    }
}

void addTextToFile(const char* inputFileName, const char* outputFileName)
{
    char userInput;
    while (true) {
        std::cout << "Add text to the file? (y/n): ";
        std::cin >> userInput;
        if (userInput == 'y') {
            appendToFile(inputFileName);
            processFile(inputFileName, outputFileName);
            sortFile(outputFileName);
            printFiles(inputFileName, outputFileName);

        }
        else if (userInput == 'n') {
            std::cout << "Bye-bye" << std::endl;
            exit(0);
        }
        else {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    }
}







