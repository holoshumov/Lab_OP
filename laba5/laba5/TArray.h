#pragma once
#include <iostream>
#include <random>

class TArray
{
protected:
    int size = 5;
    int intValue;
    double doubleValue;
public:
    virtual void IncreaseAll(int value) = 0;
    virtual void DecreaseAll(double value) = 0;
    virtual void FillRandomly() = 0;
    virtual double GetAverage() = 0;
    virtual  void PrintArray() = 0;
};