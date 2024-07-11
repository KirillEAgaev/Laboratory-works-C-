#include <iostream>
#include <locale.h>

using namespace std;

// Рекурсивная функция для перевода числа из десятичной в двоичную систему
void decimalToBinary(int num) {
    if (num > 0) {
        decimalToBinary(num / 2);
        cout << num % 2;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int num;
    cout << "Введите целое положительное число для перевода в двоичную систему: ";
    cin >> num;

    if (num > 0) {
        cout << "Двоичное представление числа " << num << " : ";
        decimalToBinary(num);
        cout << endl;
    }
    else {
        cout << "Введите целое положительное число." << endl;
    }

    return 0;
}