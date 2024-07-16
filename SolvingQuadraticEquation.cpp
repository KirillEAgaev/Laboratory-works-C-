#include <iostream>
#include <cmath>

using namespace std;

struct QuadraticEquationSolution {
    double root1;
    double root2;
};

QuadraticEquationSolution solveQuadraticEquation(double a, double b, double c) {
    QuadraticEquationSolution solution;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        solution.root1 = solution.root2 = 0;
    }
    else if (discriminant == 0) {
        solution.root1 = solution.root2 = -b / (2 * a);
    }
    else {
        solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
        solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    return solution;
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

    QuadraticEquationSolution solution = solveQuadraticEquation(a, b, c);

    cout << "Корни квадратного уравнения:" << endl;
    cout << "x1 = " << solution.root1 << endl;
    cout << "x2 = " << solution.root2 << endl;

    return 0;
}