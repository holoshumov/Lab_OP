#include "header.h"
#include "TArray.h"

int main()
{
    int m;
    std::cout << "Enter m: ";
    std::cin >> m;
    intArray** intArrays;
    DoubleArray** doubleArrays;
    createArrays(intArrays, doubleArrays, m);
    printArrays(intArrays, doubleArrays, m);
    int value;
    std::cout << "Enter the value to increase/decrease the arrays: ";
    std::cin >> value;
    modifyArrays(intArrays, doubleArrays, m, value);
    printArrays(intArrays, doubleArrays, m);
    findMaxAverageArray(intArrays, doubleArrays, m);
    freeMemory(intArrays, doubleArrays, m);
    return 0;
}