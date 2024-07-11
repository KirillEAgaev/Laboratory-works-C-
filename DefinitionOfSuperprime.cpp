#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int number;

    cout << "Введите число: ";
    cin >> number;

    // Проверка на простоту
    bool isPrime = true;
    if (number <= 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    // Проверка на суперпростоту
    if (isPrime) {
        int sumDigits = 0;
        int productDigits = 1;
        int currentDigit = 0;
        int tempNumber = number;

        while (tempNumber > 0) {
            currentDigit = tempNumber % 10;
            sumDigits += currentDigit;
            productDigits *= currentDigit;
            tempNumber /= 10;
        }

        bool isSuperPrime = true;
        if (sumDigits <= 1 || productDigits <= 1) {
            isSuperPrime = false;
        }
        else {
            for (int i = 2; i * i <= sumDigits; i++) {
                if (sumDigits % i == 0) {
                    isSuperPrime = false;
                    break;
                }
            }

            if (isSuperPrime) {
                for (int i = 2; i * i <= productDigits; i++) {
                    if (productDigits % i == 0) {
                        isSuperPrime = false;
                        break;
                    }
                }
            }
        }

        if (isSuperPrime) {
            cout << number << " является суперпростым числом." << endl;
        }
        else {
            cout << number << " не является суперпростым числом." << endl;
        }

    }
    else {
        cout << number << " не является суперпростым числом, так как не является простым числом." << endl;
    }

    return 0;
}