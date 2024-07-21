#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// ��������������
	vector<int> scores;
	// ���������� ������ �������� � ������
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	// �������� ������� ������ student
	human* stud = new student("������", "����", "����������", scores);

	// �������� ������� ������ teacher
	unsigned int teacher_work_time = 40;
	human* tch = new teacher("�������", "�������", "���������", teacher_work_time);

	// ����� ����������� ������� ����� ��������� �� ������� �����
	cout << stud->get_full_name() << endl;
	cout << "������� ����: " << static_cast<student*>(stud)->get_average_score() << endl;
	cout << tch->get_full_name() << endl;
	cout << "���������� �����: " << static_cast<teacher*>(tch)->get_work_time() << endl;

	delete stud;
	delete tch;
	return 0;
}
