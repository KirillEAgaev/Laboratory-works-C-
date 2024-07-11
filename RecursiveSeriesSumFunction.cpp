#include <iostream>
#include <locale.h>

using namespace std;

// Рекурсивная функция для вычисления суммы ряда
int sumSeries(int n) {
    if (n == 1) {
        return 5;
    }
    else {
        return 5 * n + sumSeries(n - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите значение n: ";
    cin >> n;

    if (n > 0) {
        int result = sumSeries(n);
        cout << "Сумма ряда для n = " << n << " равна: " << result << endl;
    }
    else {
        cout << "Введите значение n больше нуля." << endl;
    }

    return 0;
}