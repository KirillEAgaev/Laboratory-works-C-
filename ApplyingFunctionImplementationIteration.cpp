#include <iostream>
#include <cmath>
using namespace std;

// Функция вычисления кубического корня с использованием стандартной функции pow
double cubeRootPow(double a) {
    return pow(a, 1.0 / 3.0);
}

// Функция вычисления кубического корня с использованием итерационной формулы
double cubeRootIterative(double a) {
    double xi = 1.0;
    double prevXi;

    do {
        prevXi = xi;
        xi = 1.0 / 3.0 * (a / (prevXi * prevXi) + 2 * prevXi);
    } while (abs(xi - prevXi) > 1e-6); // Проверка на достижение заданной точности

    return xi;
}

int main() {

    setlocale(LC_ALL, "Russian");

    double a;

    cout << "Введите число a для вычисления кубического корня: ";
    cin >> a;

    if (a >= 0) {
        cout << "Кубический корень числа a (pow): " << cubeRootPow(a) << endl;
        cout << "Кубический корень числа a (итерация): " << cubeRootIterative(a) << endl;
    }
    else {
        cout << "Кубический корень определен только для неотрицательных чисел." << endl;
    }

    return 0;
}