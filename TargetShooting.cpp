#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int x;
    int y;
    int kol = 0;
    string level;

    for (int i = 0; i < 3; i++) {
        cout << "Выстрел №" << i + 1 << endl;
        cout << "Введите координату x: ";
        cin >> x;
        cout << "Введите координату y: ";
        cin >> y;

        if ((x * x + y * y) < 1) {
            kol += 10;
        }
        else if ((x * x + y * y) <= 2) {
            kol += 5;
        }
        else if ((x * x + y * y) < 3) {
            kol += 0;
        }
    }

    cout << "Сумма очков: " << kol << endl;

    if (kol >= 20) {
        level = "Снайпер";
    }
    else if (kol >= 10) {
        level = "Просто стрелок";
    }
    else {
        level = "Новичок";
    }

    cout << "Уровень стрелка: " << level << endl;

    return 0;
}