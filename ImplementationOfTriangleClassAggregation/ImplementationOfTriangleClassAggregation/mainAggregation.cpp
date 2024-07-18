#include <iostream>
#include "dot.h"
#include "triangle_aggregation.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // Тестирование агрегации
    Dot* pDot1 = new Dot(0, 0);
    Dot* pDot2 = new Dot(3, 0);
    Dot* pDot3 = new Dot(0, 4);

    Triangle aggregationTriangle(pDot1, pDot2, pDot3);
    aggregationTriangle.printSideLengths();
    cout << "Периметр: " << aggregationTriangle.calculatePerimeter() << endl;
    cout << "Площадь: " << aggregationTriangle.calculateArea() << endl;

    // Освобождение памяти, выделенной для динамических объектов
    delete pDot1;
    delete pDot2;
    delete pDot3;

    return 0;
}