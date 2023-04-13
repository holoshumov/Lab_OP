#include <iostream>
#include "function.h"

int main() {
    const int MAX_SIZE = 100;
    Plane planes[MAX_SIZE];
    int ARRAY_SIZE = 0;
    Point point;
    inputPlanes(planes, ARRAY_SIZE, MAX_SIZE);
    printPlanes(planes, ARRAY_SIZE);
    createPoint(point);
    printAnswer(planes, ARRAY_SIZE, point);
    return 0;
}
