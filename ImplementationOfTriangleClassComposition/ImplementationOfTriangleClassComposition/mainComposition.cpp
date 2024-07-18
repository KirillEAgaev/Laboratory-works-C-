#include <iostream>
#include "dot.h"
#include "triangle_composition.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // ������������ ����������
    Dot dot1(0, 0);
    Dot dot2(3, 0);
    Dot dot3(0, 4);

    Triangle compositionTriangle(dot1, dot2, dot3);
    compositionTriangle.printSideLengths();
    cout << "��������: " << compositionTriangle.calculatePerimeter() << endl;
    cout << "�������: " << compositionTriangle.calculateArea() << endl;

    return 0;
}