#include <iostream>
using namespace std;

// Шаблонная функция, возвращающая среднее арифметическое массива
template <typename T>
T averageArray(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / static_cast<T>(size);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Проверка для массивов разных типов
    int intArr[] = { 1, 2, 3, 4, 5 };
    long longArr[] = { 1L, 2L, 3L, 4L, 5L };
    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    char charArr[] = { 'a', 'b', 'c', 'd', 'e' };

    cout << "Среднее значение массива int: " << averageArray(intArr, 5) << endl;
    cout << "Среднее значение массива long: " << averageArray(longArr, 5) << endl;
    cout << "Среднее значение массива double: " << averageArray(doubleArr, 5) << endl;
    cout << "Среднее значение массива char: " << averageArray(charArr, 5) << endl;

    return 0;
}