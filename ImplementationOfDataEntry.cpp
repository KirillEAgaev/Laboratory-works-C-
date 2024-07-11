#include <iostream>
#include <limits>
using namespace std;

namespace InputNamespace {
    bool Input(int& a, int& b) {
        cout << "Введите два целых числа a и b через пробел: ";

        if (!(cin >> a >> b) || cin.get() != '\n') {
            cin.clear(); // сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера ввода
            return false;
        }

        return true;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int a, b;
    if (!InputNamespace::Input(a, b)) {
        cerr << "error";
        return 1;
    }

    int s = a + b;
    cout << "Сумма a и b: " << s << endl;

    return 0;
}