#pragma once
#include "human.h"
#include <string>
using namespace std;

class teacher : public human {
	// ����������� ������ teacher
public:
	teacher(
		string last_name,
		string name,
		string second_name,
		// ���������� ������� ����� �� ������� � �������������
		unsigned int work_time
	) : human(
		last_name,
		name,
		second_name
	) {
		this->work_time = work_time;
	}
	// ��������� ���������� ������� �����
	unsigned int get_work_time()
	{
		return this->work_time;
	}

	// ��������������� ������������ ������ get_full_name()
	string get_full_name() override {
		ostringstream full_name;
		full_name << "�������������: " << human::get_full_name();
		return full_name.str();
	}

private:
	// ������� ����
	unsigned int work_time;
};