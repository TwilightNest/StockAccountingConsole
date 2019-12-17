#include "UserRole.h"
#include <iostream>

UserRole::UserRole()
{
	_productContext = ProductContext();
}

void UserRole::ShowProductsList()
{
	_productContext.ShowProductsList();
}

void UserRole::AddProduct()
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

void UserRole::UpdateProduct()
{
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << endl;

	_productContext.UpdateProduct(name);
}

void UserRole::DeleteProduct()
{
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << endl;

	_productContext.DeleteProduct(name);
}