#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Задаем номиналы монет
    vector<int> coins = { 10, 5, 2, 1 };

    int amount;
    cout << "Введите сумму для размена: ";
    cin >> amount;

    cout << "Минимальный набор монет для размена " << amount << " рублей:\n";

    for (int i = 0; i < coins.size(); i++) {
        int count = amount / coins[i];
        amount -= count * coins[i];
        if (count > 0) {
            cout << count << " монет(ы) по " << coins[i] << " рублей\n";
        }
    }

    return 0;
}