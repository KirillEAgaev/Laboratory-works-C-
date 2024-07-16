#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

tuple<double, double, bool> solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return make_tuple(0, 0, false);
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        return make_tuple(root, root, true);
    }
    else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        return make_tuple(root1, root2, true);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения (ax^2 + bx + c = 0):" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    double root1, root2;
    bool hasRoots;
    tie(root1, root2, hasRoots) = solveQuadraticEquation(a, b, c);

    if (hasRoots) {
        cout << "Корни квадратного уравнения:" << endl;
        cout << "x1 = " << root1 << endl;
        cout << "x2 = " << root2 << endl;
    }
    else {
        cout << "Квадратное уравнение не имеет действительных корней." << endl;
    }

    return 0;
}