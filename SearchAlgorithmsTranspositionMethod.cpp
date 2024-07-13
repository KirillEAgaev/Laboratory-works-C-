#include <iostream>

using namespace std;

// Функция поиска элемента методом транспозиции
int searchByTransposition(int arr[], int size, int key) {
    // Если массив пустой или ключ не найден, вернуть -1
    if (size == 0 || arr[0] != key) {
        return -1;
    }

    // Если первый элемент ключ, вернуть 0
    if (arr[0] == key) {
        return 0;
    }

    // Поиск ключа в массиве
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] == key) {
            // Если ключ найден, поменять местами текущий и предыдущий элементы
            swap(arr[i], arr[i - 1]);
            return i;
        }
    }

    // Если ключ не найден, вернуть -1
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Поиск элемента 3 методом транспозиции
    int index = searchByTransposition(arr, size, 3);
    if (index == -1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент найден на позиции: " << index << endl;
        // Вывод массива после транспозиции
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}