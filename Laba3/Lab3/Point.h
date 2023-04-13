#pragma once
#include <iostream>

class Point {
private:
    double x;
    double y;
    double z;

public:
    Point();
    Point(double x_val, double y_val, double z_val);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x_val);
    void setY(double y_val);
    void setZ(double z_val);
};

