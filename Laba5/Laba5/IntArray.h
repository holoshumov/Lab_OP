#pragma once
#include "TArray.h"

class intArray : public TArray
{
private:
    int* arr;

public:
    intArray();
    void IncreaseAll(int value) override;
    void DecreaseAll(double value) override;
    double GetAverage() override;
    void FillRandomly() override;
    void PrintArray() override;
    virtual ~intArray();
};

