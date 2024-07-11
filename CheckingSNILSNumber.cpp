#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string snils;
    cout << "Введите номер СНИЛС: ";
    cin >> snils;

    // Проверка длины номера
    if (snils.length() != 11) {
        cout << "Неправильная длина номера СНИЛС\n";
        return 0;
    }

    // Проверка наличия только цифр
    for (int i = 0; i < snils.length(); i++) {
        if (!isdigit(snils[i])) {
            cout << "Номер СНИЛС может содержать только цифры\n";
            return 0;
        }
    }

    // Проверка одинаковых цифр подряд
    for (int i = 0; i < snils.length() - 2; i++) {
        if (snils[i] == snils[i + 1] && snils[i + 1] == snils[i + 2]) {
            cout << "В номере СНИЛС не может быть более двух одинаковых цифр подряд\n";
            return 0;
        }
    }

    // Вычисление контрольного числа
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += (snils[i] - '0') * (9 - i);
    }

    int control_number;
    if (sum < 100) {
        control_number = sum;
    }
    else if (sum == 100 || sum == 101) {
        control_number = 0;
    }
    else {
        int remainder = sum % 101;
        if (remainder < 100) {
            control_number = remainder;
        }
        else {
            control_number = 0;
        }
    }

    int input_control_number = stoi(snils.substr(9, 2));

    // Проверка валидности номера СНИЛС
    if (control_number == input_control_number) {
        cout << "Номер СНИЛС валиден\n";
    }
    else {
        cout << "Номер СНИЛС не валиден\n";
    }

    return 0;
}