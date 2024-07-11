#include <iostream>
#include <cmath>
using namespace std;

int Myroot(double a, double b, double c, double& x1, double& x2) {
    double D = b * b - 4 * a * c;

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        return 1;
    }
    else if (D == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;
    cout << "Введите значение c: ";
    cin >> c;

    double x1, x2;

    int result = Myroot(a, b, c, x1, x2);

    if (result == 1) {
        cout << "Корни уравнения " << a << "x^2 + " << b << "x + " << c << " = 0: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (result == 0) {
        cout << "Корень уравнения " << a << "x^2 + " << b << "x + " << c << " = 0: x1 = x2 = " << x1 << endl;
    }
    else {
        cout << "Корней уравнения " << a << "x^2 + " << b << "x + " << c << " = 0 нет" << endl;
    }

    return 0;
}