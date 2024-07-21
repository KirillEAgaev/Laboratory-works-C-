#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// Оценкистудента
	vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	// Создание объекта класса student
	human* stud = new student("Петров", "Иван", "Алексеевич", scores);

	// Создание объекта класса teacher
	unsigned int teacher_work_time = 40;
	human* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

	// Вызов виртуальных методов через указатели на базовый класс
	cout << stud->get_full_name() << endl;
	cout << "Средний балл: " << static_cast<student*>(stud)->get_average_score() << endl;
	cout << tch->get_full_name() << endl;
	cout << "Количество часов: " << static_cast<teacher*>(tch)->get_work_time() << endl;

	delete stud;
	delete tch;
	return 0;
}
