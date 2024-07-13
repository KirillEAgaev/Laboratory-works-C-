#include <iostream>
#include <limits.h>

using namespace std;

// Вычисление суммы элементов массива
int sumArrayElements(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Вычисление среднего значения элементов массива
int averageArrayElements(int* arr, int n) {
    int sum = sumArrayElements(arr, n);
    return sum / n;
}

// Вычисление суммы отрицательных и положительных элементов массива
void sumNegativePositiveElements(int* arr, int n, int& sumNegative, int& sumPositive) {
    sumNegative = 0;
    sumPositive = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            sumNegative += arr[i];
        else
            sumPositive += arr[i];
    }
}

// Вычисление суммы элементов с четными и нечетными индексами
void sumEvenOddIndexElements(int* arr, int n, int& sumEven, int& sumOdd) {
    sumEven = 0;
    sumOdd = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            sumEven += arr[i];
        else
            sumOdd += arr[i];
    }
}

// Вычисление индексов минимального и максимального элементов
void minMaxIndices(int* arr, int n, int& minIndex, int& maxIndex) {
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
}

// Вычисление произведения элементов между минимальным и максимальным
int productBetweenMinMax(int* arr, int n, int minIndex, int maxIndex) {
    int start = minIndex < maxIndex ? minIndex : maxIndex;
    int end = minIndex < maxIndex ? maxIndex : minIndex;
    int product = 1;
    for (int i = start + 1; i < end; i++) {
        product *= arr[i];
    }
    return product;
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    int sum = sumArrayElements(mas, n);
    cout << "Сумма всех элементов массива: " << sum << endl;

    int average = averageArrayElements(mas, n);
    cout << "Среднее значение элементов массива: " << average << endl;

    int sumNegative, sumPositive;
    sumNegativePositiveElements(mas, n, sumNegative, sumPositive);
    cout << "Сумма отрицательных элементов: " << sumNegative << endl;
    cout << "Сумма положительных элементов: " << sumPositive << endl;

    int sumEven, sumOdd;
    sumEvenOddIndexElements(mas, n, sumEven, sumOdd);
    cout << "Сумма элементов с нечетными индексами: " << sumOdd << endl;
    cout << "Сумма элементов с четными индексами: " << sumEven << endl;

    int minIndex, maxIndex;
    minMaxIndices(mas, n, minIndex, maxIndex);
    cout << "Индекс минимального элемента: " << minIndex << endl;
    cout << "Индекс максимального элемента: " << maxIndex << endl;

    int product = productBetweenMinMax(mas, n, minIndex, maxIndex);
    cout << "Произведение элементов между минимальным и максимальным: " << product << endl;

    return 0;
}