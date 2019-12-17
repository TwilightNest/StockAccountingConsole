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