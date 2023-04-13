#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(double x_val, double y_val, double z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

void Point::setX(double x_val) {
    x = x_val;
}

void Point::setY(double y_val) {
    y = y_val;
}

void Point::setZ(double z_val) {
    z = z_val;
}
