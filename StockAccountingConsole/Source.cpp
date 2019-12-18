#include "AdminRole.h"
#include "UserRole.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void RunAsAdministrator(AdminRole& admin)
{
	while (true)
	{
		cout << "Choose operation:\n1)Show products list\n2)Add product\n3)Update product\n4)Delete product\n5)Sort product\n6)Search product\n7)Show users list\n8)Add user\n9)Update user\n10)Delete user\n11)Sort user\n12)Search user\n13)Individual task\n???)Exit\nInput: ";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			admin.ShowProductsList();
			break;
		}
		case 2:
		{
			admin.AddProduct();
			break;
		}
		case 3:
		{
			admin.UpdateProduct();
			break;
		}
		case 4:
		{
			admin.DeleteProduct();
			break;
		}
		case 5:
		{
			admin.SortProduct();
			break;
		}
		case 6:
		{
			admin.SearchProduct();
			break;
		}
		case 7:
		{
			admin.ShowUsersList();
			break;
		}
		case 8:
		{
			admin.AddUser();
			break;
		}
		case 9:
		{
			admin.UpdateUser();
			break;
		}
		case 10:
		{
			admin.DeleteUser();
			break;
		}
		case 11:
		{
			admin.SortUser();
			break;
		}
		case 12:
		{
			admin.SearchUser();
			break;
		}
		case 13:
		{
			admin.IndividualTask();
			break;
		}
		default:
			cout << "Invalid choise! Exit..." << endl;
			return;
		}
	}
}

void RunAsUser(UserRole& user)
{
	while (true)
	{
		cout << "Choose operation:\n1)Show products list\n2)Add product\n3)Update product\n4)Delete product\n5)Sort product\n6)Search product\nInput: ";
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			user.ShowProductsList();
			break;
		}
		case 2:
		{
			user.AddProduct();
			break;
		}
		case 3:
		{
			user.UpdateProduct();
			break;
		}
		case 4:
		{
			user.DeleteProduct();
			break;
		}
		case 5:
		{
			user.SortProduct();
			break;
		}
		case 6:
		{
			user.SearchProduct();
			break;
		}
		default:
			cout << "Invalid choice! Exit..." << endl;
			return;
		}
	}
}

User GetUserFromString(string& str)
{
	stringstream ss(str);
	string token;
	vector<string> tmp;
	while (getline(ss, token, '\t'))
	{
		tmp.push_back(token);
	}
	User user(tmp[0], tmp[1], tmp[2], tmp[3]);
	return user;
}

int Login(string& login, string& password)
{
	ifstream _is;
	auto users = vector<User>();
	_is.open("Users.txt", ios_base::in);
	string str;
	while (getline(_is, str))
	{
		users.push_back(GetUserFromString(str));
	}
	_is.close();
	for (int i = 0; i < users.size(); ++i)
	{
		if (users[i].Login == login)
			if (users[i].Password == password)
				if (users[i].IsAdmin == "1")
					return 1;
				else
					return 0;
			else
				return -1;
	}
	return 666;
}

int main()
{
	while (true)
	{
		string login;
		string password;
		cout << "Enter login: ";
		cin >> login;
		cout << endl << "Enter password: ";
		cin >> password;
		cout << endl;
		auto role = Login(login, password);
		switch (role)
		{
		case 0:
		{
			auto user = UserRole();
			RunAsUser(user);
			break;
		}
		case 1:
		{
			auto admin = AdminRole();
			RunAsAdministrator(admin);
			break;
		}
		case -1:
		{
			cout << "Wrong password" << endl;
			break;
		}
		case 666:
		{
			cout << "No such user" << endl;
			break;
		}
		}
	}
}