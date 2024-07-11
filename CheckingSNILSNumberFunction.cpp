#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool validateSNILS(string snils) {
    // Удаление всех пробелов и дефисов из строки
    snils.erase(remove_if(snils.begin(), snils.end(), [](unsigned char c) { return isspace(c) || c == '-'; }), snils.end());

    // Проверка наличия только цифр в строке
    for (char c : snils) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // Проверка длины строки
    if (snils.length() != 11) {
        return false;
    }

    // Алгоритм проверки по заданной формуле
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += (snils[i] - '0') * (9 - i);
    }
    int expectedChecksum = (sum % 101) % 100;
    int actualChecksum = stoi(snils.substr(9, 2));

    return (expectedChecksum == actualChecksum);
}

int main() {
    setlocale(LC_ALL, "Russian");

    string snils;

    cout << "Введите номер СНИЛС: ";
    getline(cin, snils);

    if (validateSNILS(snils)) {
        cout << "Номер СНИЛС валидный" << endl;
    }
    else {
        cout << "Номер СНИЛС невалидный" << endl;
    }

    return 0;
}