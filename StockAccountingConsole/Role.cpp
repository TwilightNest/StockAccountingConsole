#include "Role.h"
#include <iostream>

Role::Role(string login, string password)
{
	Login(login, password);
	_productContext = ProductContext("products.txt");
}

void Role::ShowProducts()
{
	_productContext.ShowProductsList();
}

void Role::AddProoduct()
{
	string name;
	int count;
	int price;
	string date;
	string fio;
	cout << "Input name: ";
	cin >> name;
	cout << endl << "Input count: ";
	cin >> count;
	cout << endl << "Input price: ";
	cin >> price;
	cout << endl << "Input date: ";
	cin >> date;
	cout << endl << "Input FIO: ";
	cin >> fio;
	cout << endl;
	Product newProduct(name, count, price, Product::ConvertStringToDate(date), fio);
	_productContext.AddProduct(newProduct);
}

void Role::ChangeProduct()
{

}

void Role::DeleteProduct()
{

}

void Role::Login(string login, string password)
{

}