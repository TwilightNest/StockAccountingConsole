#include <windows.h>
#include <iostream>
#include "Admin.h"
#include "User.h"

using namespace std;

void RunAsAdministrator()
{
	while (true)
	{
		Admin admin("Admin", "Admin");
		cout << "Choose operation:\n1)Show products list\n2)Add product\n3)Change product\n4)Delete product\n5)Show users list\n6)Add user\n7)Change user\n8)Delete user\n9)Individual task\nInput: ";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			admin.ShowProducts();
			break;
		}
		case 2:
		{
			admin.AddProoduct();
			break;
		}
		default:
			cout << "Invalid choise, exit...";
			return;
		}
	}
}

void RunAsUser()
{

}

void main()
{
	RunAsAdministrator();
}