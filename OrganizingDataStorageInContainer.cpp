#include <iostream>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

struct StudentGrade {
    string name;
    char grade;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    map<string, char> grades;

    while (true) {
        cout << "Введите имя учащегося (или 'q', чтобы выйти): ";
        string name;
        getline(cin, name);

        if (name == "q") {
            break;
        }

        cout << "Введите оценку для " << name << ": ";
        char grade;
        cin >> grade;
        cin.ignore(); // Ignore newline character

        grades[name] = grade;
        cout << "Оценка для " << name << " присваивается " << grade << ".\n";
    }

    cout << "\nОценки учащихся:\n";
    for (const auto& pair : grades) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}