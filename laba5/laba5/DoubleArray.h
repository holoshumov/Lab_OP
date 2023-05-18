#pragma once
#include "TArray.h"

class DoubleArray : public TArray
{
private:
    double* arr;

public:
    DoubleArray();
    virtual ~DoubleArray();

    void DecreaseAll(double value) override;
    double GetAverage() override;
    void FillRandomly() override;
    void PrintArray() override;
    void IncreaseAll(int value) override;
};

