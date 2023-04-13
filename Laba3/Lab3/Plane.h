
#pragma once
#include <iostream>
#include "Point.h"


class Plane {
private:
    double a, b, c, d;

public:
    Plane();
    Plane(double a, double b, double c, double d);
    double getA();
    double getB();
    double getC();
    double getD();
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);
    bool contains(Point p);

};

