#pragma once
#pragma once
#include <iostream>
#include "Plane.h"
#include "Point.h"
//using namespace std;

void inputPlanes(Plane planes[], int& ARRAY_SIZE, const int MAX_SIZE);

void printPlanes(Plane planes[], const int ARRAY_SIZE);

Point createPoint(Point& p);

void printAnswer(Plane planes[], const int ARRAY_SIZE, Point& point);




