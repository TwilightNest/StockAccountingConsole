#include "Admin.h"

Admin::Admin(string login, string password)
{
	Name = login;
	_password = password;
	_context = ProductContext("products.txt");
}

void Admin::ShowProducts()
{
	_context.ShowProductsList();
}

void Admin::Login(string login, string password)
{
	try
	{

	}
	catch (const std::exception&)
	{

	}
}