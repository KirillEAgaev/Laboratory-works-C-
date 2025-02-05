﻿#include <iostream>
using namespace std;

int* max_vect(int size, int* a, int* b) {
    int* result = new int[size]; // Создаем новый массив размером size
    for (int i = 0; i < size; i++) {
        result[i] = (a[i] > b[i]) ? a[i] : b[i]; // Заполняем результирующий массив большими элементами
    }
    return result; // Возвращаем указатель на созданный массив
}

int main() {
    setlocale(LC_ALL, "Russian");

    int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };
    int kc = sizeof(a) / sizeof(a[0]); // Количество элементов массива
    int* c; // Указатель на результирующий массив
    c = max_vect(kc, a, b); // Вызов функции для создания массива
    for (int i = 0; i < kc; i++) // Вывод результата
        cout << c[i] << " ";
    cout << endl;
    delete[] c; // Возврат памяти
    return 0;
}