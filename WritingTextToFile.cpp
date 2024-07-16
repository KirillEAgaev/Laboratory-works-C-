#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    // Устанавливаем локаль, чтобы работать с русским языком
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string filename = "poem.txt";
    ofstream file(filename, ios::out | ios::binary); // Открываем файл для записи в бинарном режиме

    if (!file.is_open()) { // Проверяем, удалось ли открыть файл
        cout << "Не удалось открыть файл " << filename << endl;
        return 1;
    }

    cout << "Введите стихотворение (по одной строке за раз, введите пустую строку, чтобы закончить):\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line.empty()) { // Пустая строка означает конец ввода
            break;
        }
        file << line << endl; // Записываем строку в файл
    }

    file.close(); // Закрываем файл
    cout << "Стихотворение сохранено в файле " << filename << endl;

    return 0;
}