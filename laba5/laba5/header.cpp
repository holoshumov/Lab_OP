
#include "header.h"
void createArrays(intArray**& intArrays, DoubleArray**& doubleArrays, int m)
{
    intArrays = new intArray * [m];
    doubleArrays = new DoubleArray * [m];

    for (int i = 0; i < m; i++)
    {
        intArrays[i] = new intArray();
        intArrays[i]->FillRandomly();
        doubleArrays[i] = new DoubleArray();
        doubleArrays[i]->FillRandomly();
    }
}

void printArrays(intArray** intArrays, DoubleArray** doubleArrays, int m)
{
    std::cout << "Int Arrays:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        std::cout << "Array #" << i + 1 << ": ";
        intArrays[i]->PrintArray();
    }
    std::cout << std::endl << "Double Arrays:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        std::cout << "Array  #" << i + 1 << ": ";
        doubleArrays[i]->PrintArray();
    }
}

void modifyArrays(intArray** intArrays, DoubleArray** doubleArrays, int m, int value)
{
    for (int i = 0; i < m; i++)
    {
        intArrays[i]->IncreaseAll(value);
        doubleArrays[i]->DecreaseAll(value);
    }
}


void findMaxAverageArray(intArray** intArrays, DoubleArray** doubleArrays, int m)
{
    int maxAverageIndex = -1;
    double maxAverage = 0.0;

    for (int i = 0; i < m; i++)
    {
        double intArrayAverage = intArrays[i]->GetAverage();
        double doubleArrayAverage = doubleArrays[i]->GetAverage();

        double arrayAverage = std::max(intArrayAverage, doubleArrayAverage);

        if (arrayAverage > maxAverage)
        {
            maxAverage = arrayAverage;
            maxAverageIndex = i;
        }
    }

    std::cout << "Array with the highest average: ";
    if (maxAverageIndex >= 0 && maxAverageIndex < m)
    {
        if (intArrays[maxAverageIndex]->GetAverage() > doubleArrays[maxAverageIndex]->GetAverage())
            intArrays[maxAverageIndex]->PrintArray();
        else
            doubleArrays[maxAverageIndex]->PrintArray();

        std::cout << "Average: " << maxAverage << std::endl;
    }
    else
    {
        std::cout << "No array found." << std::endl;
    }
}


void freeMemory(intArray** intArrays, DoubleArray** doubleArrays, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete intArrays[i];
        delete doubleArrays[i];
    }
    delete[] intArrays;
    delete[] doubleArrays;
}
