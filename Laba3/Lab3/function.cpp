#include "function.h"
#include "Point.h"
#include "Plane.h"

void inputPlanes(Plane planes[], int& ARRAY_SIZE, const int MAX_SIZE)
{
    bool continue_input = true;
    std::cout << "Enter the coefficients for plane " << std::endl;
    while (continue_input && ARRAY_SIZE < MAX_SIZE)
    {
        double a, b, c, d;

        std::cout << "A: ";
        std::cin >> a;
        std::cout << "B: ";
        std::cin >> b;
        std::cout << "C: ";
        std::cin >> c;
        std::cout << "D: ";
        std::cin >> d;

        planes[ARRAY_SIZE] = Plane(a, b, c, d);
        ARRAY_SIZE++;

        char response;
        bool valid_response = false;
        do
        {
            std::cout << "Do you want to enter another plane? (y/n): ";
            std::cin >> response;
            if (response == 'y' || response == 'Y' || response == 'n' || response == 'N')
            {
                valid_response = true;
            }
            else
            {
                std::cout << "Invalid response. Please enter 'y' or 'n'." << std::endl;
            }
        } while (!valid_response);

        if (response != 'y' && response != 'Y')
        {
            continue_input = false;
        }

    }
}

void printPlanes(Plane planes[], const int ARRAY_SIZE)
{
    std::cout << std::endl << "Planes: " << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (planes[i].getA() != 0)
        {
            if (planes[i].getA() > 0)
            {
                std::cout << planes[i].getA() << "x";
            }
            else
            {
                std::cout << "- " << -planes[i].getA() << "x";
            }
        }

        if (planes[i].getB() != 0)
        {
            if (planes[i].getB() > 0)
            {
                if (planes[i].getA() != 0)
                {
                    std::cout << " + ";
                }
                std::cout << planes[i].getB() << "y";
            }
            else
            {
                std::cout << " - " << -planes[i].getB() << "y";
            }
        }

        if (planes[i].getC() != 0)
        {
            if (planes[i].getC() > 0)
            {
                if (planes[i].getA() != 0 || planes[i].getB() != 0)
                {
                    std::cout << " + ";
                }
                std::cout << planes[i].getC() << "z";
            }
            else
            {
                std::cout << " - " << -planes[i].getC() << "z";
            }
        }

        if (planes[i].getD() != 0)
        {
            if (planes[i].getD() > 0)
            {
                if (planes[i].getA() != 0 || planes[i].getB() != 0 || planes[i].getC() != 0)
                {
                    std::cout << " + ";
                }
                std::cout << planes[i].getD();
            }
            else
            {
                std::cout << " - " << -planes[i].getD();
            }
        }

        std::cout << " = 0" << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }
}

Point createPoint(Point& point) {
    double x_val, y_val, z_val;
    std::cout << std::endl << "Enter x coordinate: ";
    std::cin >> x_val;
    std::cout << "Enter y coordinate: ";
    std::cin >> y_val;
    std::cout << "Enter z coordinate: ";
    std::cin >> z_val;
    point.setX(x_val);
    point.setY(y_val);
    point.setZ(z_val);
    return point;
}

void printAnswer(Plane planes[], const int ARRAY_SIZE, Point& point)
{
    std::cout << std::endl << "Point belongs to plane:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (planes[i].contains(point)) {

            if (planes[i].getA() != 0) {
                if (planes[i].getA() > 0) {
                    std::cout << planes[i].getA() << "x";
                }
                else {
                    std::cout << "- " << -planes[i].getA() << "x";
                }
            }

        	if (planes[i].getB() != 0) {
                if (planes[i].getB() > 0) {
                    if (planes[i].getA() != 0) {
                        std::cout << " + ";
                    }
                    std::cout << planes[i].getB() << "y";
                }
                else {
                    std::cout << " - " << -planes[i].getB() << "y";
                }
            }

            if (planes[i].getC() != 0) {
                if (planes[i].getC() > 0) {
                    if (planes[i].getA() != 0 || planes[i].getB() != 0) {
                        std::cout << " + ";
                    }
                    std::cout << planes[i].getC() << "z";
                }
                else {
                    std::cout << " - " << -planes[i].getC() << "z";
                }
            }

            if (planes[i].getD() != 0) {
                if (planes[i].getD() > 0) {
                    if (planes[i].getA() != 0 || planes[i].getB() != 0 || planes[i].getC() != 0) {
                        std::cout << " + ";
                    }
                    std::cout << planes[i].getD();
                }
                else {
                    std::cout << " - " << -planes[i].getD();
                }
            }

            std::cout << " = 0" << std::endl;
            std::cout << "---------------------------------" << std::endl;

        }

    }

}





