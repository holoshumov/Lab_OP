#pragma once
#define M_PI 3.14159265358979323846

class TruncatedCone {
private:
    double height;
    double radius_bottom;
    double radius_top;

public:
    TruncatedCone(double h, double rb, double rt);

    double getHeight() const;
    double getBottomRadius() const;
    double getTopRadius() const;
    double volume() const;
};
