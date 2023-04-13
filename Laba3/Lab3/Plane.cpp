#include "Plane.h"
#include "Point.h"

Plane::Plane() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

Plane::Plane(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

double Plane::getA()
{
    return a;
}

double Plane::getB() {
    return b;
}

double Plane::getC() {
    return c;
}

double Plane::getD()
{
    return d;
}

void Plane::setA(double a)
{
    this->a = a;
}

void Plane::setB(double b)
{
    this->b = b;
}

void Plane::setC(double c)
{
    this->c = c;
}

void Plane::setD(double d)
{
    this->d = d;
}

bool Plane::contains(Point p)
{
    double result = a * p.getX() + b * p.getY() + c * p.getZ() + d;

    return result == 0;

}

