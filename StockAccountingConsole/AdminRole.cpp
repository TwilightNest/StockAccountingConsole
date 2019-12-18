#include "AdminRole.h"
#include "iostream"

AdminRole::AdminRole()
{
	_productContext = ProductContext();
	_userContext = UsersContext();
}

void AdminRole::ShowProductsList()
{
	_productContext.ShowProductsList();
}

void AdminRole::AddProduct()
{
	string name;
	int count;
	int price;
	string date;
	string fio;

	cout << "Enter name: ";
	cin >> name;
	cout << endl << "Enter count: ";
	cin >> count;
	cout << endl << "Enter price: ";
	cin >> price;
	cout << endl << "Enter date(dd::mm::yy): ";
	cin >> date;
	cout << endl << "Enter FIO: ";
	cin >> fio;
	cout << endl;

	Product product(name, count, price, Product::ConvertStringToDate(date), fio);
	_productContext.AddProduct(product);
}

void AdminRole::UpdateProduct()
{
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << endl;

	_productContext.UpdateProduct(name);
}

void AdminRole::DeleteProduct()
{
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << endl;

	_productContext.DeleteProduct(name);
}

void AdminRole::SortProduct()
{
	int choice;
	cout << "Sort for: \n1)Name\n2)Count\n3)Price\nInput: ";
	cin >> choice;
	cout << endl;
	_productContext.SortProduct(choice);
}

void AdminRole::SearchProduct()
{
	int choice;
	string str;
	cout << "Search for: \n1)Name\n2)Count\n3)Price\nInput: ";
	cin >> choice;
	cout << endl << "Input string for search: ";
	cin >> str;
	cout << endl;
	_productContext.SearchProduct(str, choice);
}

void AdminRole::ShowUsersList()
{
	_userContext.ShowUsersList();
}

void AdminRole::AddUser()
{
	string login;
	string name;
	string password;
	string isAdmin;

	cout << "Enter login: ";
	cin >> login;
	cout << endl << "Enter name: ";
	cin >> name;
	cout << endl << "Enter password: ";
	cin >> password;
	cout << endl << "Enter role(1 - Administrator, 0 - User): ";
	cin >> isAdmin;
	cout << endl;

	User user(login, name, password, isAdmin);
	_userContext.AddUser(user);
}

void AdminRole::UpdateUser()
{
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << endl;

	_userContext.UpdateUser(name);
}

void AdminRole::DeleteUser()
{
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << endl;

	_userContext.DeleteUser(name);
}

void AdminRole::SortUser()
{
	int choice;
	cout << "Sort for: \n1)Login\n2)Name\n3)Admin\nInput: ";
	cin >> choice;
	cout << endl;
	_userContext.SortUser(choice);
}

void AdminRole::SearchUser()
{
	int choice;
	string str;
	cout << "Search for: \n1)Login\n2)Name\n3)Admin\nInput: ";
	cin >> choice;
	cout << endl << "Input string for search: ";
	cin >> str;
	cout << endl;
	_userContext.SearchUser(str, choice);
}

void AdminRole::IndividualTask()
{
	int x;
	int y;
	cout << "Enter x: ";
	cin >> x;
	cout << endl << "Enter y: ";
	cin >> y;
	cout << endl;
	_productContext.IndividualTask(x, y);
}