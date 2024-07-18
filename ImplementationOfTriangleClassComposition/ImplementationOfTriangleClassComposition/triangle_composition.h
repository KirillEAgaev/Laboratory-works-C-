#pragma once
#pragma once
#include "dot.h"
using namespace std;

class Triangle
{
private:
    Dot point1, point2, point3;

public:
    Triangle(Dot p1, Dot p2, Dot p3);
    void printSideLengths();
    double calculatePerimeter();
    double calculateArea();
};