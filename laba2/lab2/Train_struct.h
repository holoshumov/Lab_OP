#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Train
{
    string number;
    string direction;
    string departureTime;
    string arrivalTime;

    void scheduleInput();
    void printSchedule();
};
