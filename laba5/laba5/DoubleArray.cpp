#include "DoubleArray.h"

DoubleArray::DoubleArray()
{
    arr = new double[size];
}

DoubleArray::~DoubleArray()
{
    delete[] arr;
}

void DoubleArray::DecreaseAll(double value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] -= value;
    }
}

double DoubleArray::GetAverage()
{
    if (size == 0)
    {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

void DoubleArray::FillRandomly()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(-100.0, 100.0);

    for (int i = 0; i < size; i++)
    {
        double randomValue = distribution(generator);
        arr[i] = round(randomValue * 100) / 100.0;
    }
}

void DoubleArray::PrintArray()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void DoubleArray::IncreaseAll(int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += value;
    }
}
