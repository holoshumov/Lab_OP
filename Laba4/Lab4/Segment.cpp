#include "Segment.h"

Segment::Segment() : x1(0), y1(0), x2(0), y2(0) {}

Segment::Segment(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

Segment::Segment(const Segment& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {}

double Segment::getX1() const {
    return x1;
}

double Segment::getY1() const {
    return y1;
}

double Segment::getX2() const {
    return x2;
}

double Segment::getY2() const {
    return y2;
}

bool Segment::contains(double x, double y) const {
    double dxc = x - x1;
    double dyc = y - y1;
    double dxl = x2 - x1;
    double dyl = y2 - y1;
    double cross = dxc * dyl - dyc * dxl;
    if (std::abs(cross) > 0.000001) {
        return false;
    }
    if (std::abs(dxl) >= std::abs(dyl)) {
        if (dxl > 0) {
            return x1 <= x && x <= x2;
        }
        else {
            return x2 <= x && x <= x1;
        }
    }
    else {
        if (dyl > 0) {
            return y1 <= y && y <= y2;
        }
        else {
            return y2 <= y && y <= y1;
        }
    }
}

Segment Segment::operator+(const Segment& other) const {
    return Segment(x1 + other.x1, y1 + other.y1, x2 + other.x2, y2 + other.y2);
}

Segment Segment::operator++(int) {
    Segment temp(*this);
    x2++;
    y2++;
    return temp;
}
