#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Train_struct.h"

using namespace std;

string inputForFile();
void readFile(const string& filename, string schedule = "Summer Schedule");
void winterSchedule(const string& filename);
void writeToFile(const string& filename, const Train& train);
