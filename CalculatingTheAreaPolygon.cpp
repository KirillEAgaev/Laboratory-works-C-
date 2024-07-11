#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x[5], y[5], area;

    cout << "Введите координаты вершин пятиугольника (x, y):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Вершина " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    area = 0.5 * abs((x[0] * y[1] + x[1] * y[2] + x[2] * y[3] + x[3] * y[4] + x[4] * y[0]) -
        (y[0] * x[1] + y[1] * x[2] + y[2] * x[3] + y[3] * x[4] + y[4] * x[0]));

    cout << "Площадь пятиугольника: " << area << endl;

    return 0;
}