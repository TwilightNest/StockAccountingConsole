#include <iostream>
#include "FilesWorker.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "�������� ������������: \n1)�������������\n2)������������\n��� �����: ";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		default:
			cout << "����������� �����, ����� �� ���������...";
			return;
		}
	}
}