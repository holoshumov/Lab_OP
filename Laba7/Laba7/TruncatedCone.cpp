#include "pch.h"
#include "TruncatedCone.h"
#include <cmath>

#define M_PI 3.14159265358979323846


TruncatedCone::TruncatedCone(double h, double rb, double rt) {
    height = h;
    radius_bottom = rb;
    radius_top = rt;
}

double TruncatedCone::getHeight() const {
    return height;
}

double TruncatedCone::getBottomRadius() const {
    return radius_bottom;
}

double TruncatedCone::getTopRadius() const {
    return radius_top;
}

double TruncatedCone::volume() const {
    return (M_PI * height / 3) * (pow(radius_bottom, 2) + pow(radius_top, 2) + radius_bottom * radius_top);
}
