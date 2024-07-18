#include <iostream>
#include <cmath>

using namespace std;

class TriangleException : public exception {
public:
    const char* what() const noexcept override {
        return "Невозможно создать треугольник с такими сторонами";
    }
};

class Triangle {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) {
        if (a + b <= c || b + c <= a || a + c <= b) {
            throw TriangleException();
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double area() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    try {
        Triangle t(3, 4, 5);
        cout << "Площадь треугольника: " << t.area() << endl;

        // Попытка создать треугольник с недопустимыми сторонами
        Triangle t2(3, 4, 10);
    }
    catch (const TriangleException& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}