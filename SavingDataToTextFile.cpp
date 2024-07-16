#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями

    // Сортировка массива
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    // Создание файла и запись данных
    ofstream file("arrays.txt");
    if (file.is_open())
    {
        // Запись исходного массива
        file << "Исходный массив:\n";
        for (int i = 0; i < N; i++)
        {
            file << a[i] << " ";
        }
        file << "\n\n";

        // Запись отсортированного массива
        file << "Отсортированный массив:\n";
        for (int i = 0; i < N; i++)
        {
            file << a[i] << " ";
        }
        file << "\n";

        file.close();
        cout << "Данные записаны в файл 'arrays.txt'." << endl;
    }
    else
    {
        cout << "Не удалось открыть файл для записи." << endl;
    }

    return 0;
}