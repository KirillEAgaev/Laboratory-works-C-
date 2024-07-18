#include <iostream>
#include "dot.h"
#include "triangle_composition.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // Тестирование композиции
    Dot dot1(0, 0);
    Dot dot2(3, 0);
    Dot dot3(0, 4);

    Triangle compositionTriangle(dot1, dot2, dot3);
    compositionTriangle.printSideLengths();
    cout << "Периметр: " << compositionTriangle.calculatePerimeter() << endl;
    cout << "Площадь: " << compositionTriangle.calculateArea() << endl;

    return 0;
}