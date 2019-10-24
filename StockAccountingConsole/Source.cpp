#include <windows.h>
#include <iostream>
#include "FilesWorker.h"

using namespace std;

void RunAsAdministrator()
{
	while (true)
	{
		cout << "Choose operation:\n1)Show products list\n2)Add product\n3)Change product\n4)Delete product\n5)Show users list\n6)Add user\n7)Change user\n8)Delete user\n9)Individual task\nInput: ";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			FilesWorker fw("test.txt");
			fw.GetProductsList();
			break;
		}
		case 2:
		{
			break;
		}
		default:
			cout << "Invalid choise, back...";
			return;
		}
	}
}

void RunAsUser()
{

}

void main()
{
	while (true)
	{
		cout << "Choose user: \n1)Admin\n2)User\nInput: ";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			RunAsAdministrator();
			break;
		}
		case 2:
		{
			RunAsUser();
			break;
		}
		default:
			cout << "Invalid choise, exit...";
			return;
		}
	}
}