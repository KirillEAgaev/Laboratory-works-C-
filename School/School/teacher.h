#pragma once
#include "human.h"
#include <string>
using namespace std;

class teacher : public human {
	// Конструктор класса teacher
public:
	teacher(
		string last_name,
		string name,
		string second_name,
		// Количество учебных часов за семестр у преподавателя
		unsigned int work_time
	) : human(
		last_name,
		name,
		second_name
	) {
		this->work_time = work_time;
	}
	// Получение количества учебных часов
	unsigned int get_work_time()
	{
		return this->work_time;
	}

	// Переопределение виртуального метода get_full_name()
	string get_full_name() override {
		ostringstream full_name;
		full_name << "Преподаватель: " << human::get_full_name();
		return full_name.str();
	}

private:
	// Учебные часы
	unsigned int work_time;
};