#include <iostream>
#include "FilesWorker.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Выберите пользователя: \n1)Администратор\n2)Пользователь\nВаш выбор: ";
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
			cout << "Некоректный выбор, выход из программы...";
			return;
		}
	}
}