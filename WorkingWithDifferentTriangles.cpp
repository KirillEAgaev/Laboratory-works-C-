#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

// Функция для вычисления площади равностороннего треугольника
float area(float side) {
    return (sqrt(3) / 4) * side * side;
}

// Функция для вычисления площади разностороннего треугольника
float area(float a, float b, float c) {
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    cout << "Выберите тип треугольника: \n";
    cout << "1 - равносторонний\n";
    cout << "2 - разносторонний\n";
    cin >> choice;

    if (choice == 1) {
        float side;
        cout << "Введите сторону равностороннего треугольника: ";
        cin >> side;
        cout << "Площадь треугольника: " << area(side) << endl;
    }
    else if (choice == 2) {
        float a, b, c;
        cout << "Введите стороны разностороннего треугольника: ";
        cin >> a >> b >> c;
        cout << "Площадь треугольника: " << area(a, b, c) << endl;
    }

    return 0;
}