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
	cout << endl  << "Enter the value to increase/decrease the arrays: ";
    cin >> value;
    modifyArrays(intArrays, doubleArrays, m, value);
    printArrays(intArrays, doubleArrays, m);
    cout << endl;
    findMaxAverageArray(intArrays, doubleArrays, m);
    freeMemory(intArrays, doubleArrays, m);
    return 0;
}