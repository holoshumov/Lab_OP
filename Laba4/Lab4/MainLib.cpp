#include "MainLib.h"

void testSegment()
{
    double x1, y1, x2, y2;
    Segment V1(0, 0, -4, 0);
    Segment V2(3, -5, 8, -1);
    std::cout << "V1 = (" << V1.getX1() << " ; " << V1.getY1() << "), (" << V1.getX2() << " ; " << V1.getY2() << ")" << std::endl;
    std::cout << "V2 = (" << V2.getX1() << " ; " << V2.getY1() << "), (" << V2.getX2() << " ; " << V2.getY2() << ")" << std::endl << std::endl;

    Segment V3 = V1 + V2;
    std::cout << "V3 = V1 + V2 = (" << V3.getX1() << ", " << V3.getY1() << "), (" << V3.getX2() << ", " << V3.getY2() << ")" << std::endl;

    V3++;
    std::cout << "V3++ = (" << V3.getX1() << " ; " << V3.getY1() << "), (" << V3.getX2() << " ; " << V3.getY2() << ")" << std::endl << std::endl;

    //(4 -2.5)
    double x, y;
    std::cout << "Enter the coordinates of point P (x y): ";
    std::cin >> x >> y;

    if (V3.contains(x, y)) {
        std::cout << "\nPoint P belongs to segment V3" << std::endl;
    }
    else {
        std::cout << "\nPoint P does not belong to segment V3" << std::endl;
    }
}