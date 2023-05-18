#include "intArray.h"

intArray::intArray()
{
    arr = new int[size];
}

intArray::~intArray()
{
    delete[] arr;
}

void intArray::IncreaseAll(int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += value;
    }
}

double intArray::GetAverage()
{
    if (size == 0)
    {
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

void intArray::FillRandomly()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(-100, 100);

    for (int i = 0; i < size; i++)
    {
        arr[i] = distribution(generator);
    }
}

void intArray::PrintArray()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void intArray::DecreaseAll(double value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] -= value;
    }
}
