#pragma once
#include "UsersContext.h"
#include "ProductContext.h"
#include <string>

using namespace std;

class AdminRole
{
public:

	AdminRole();

	void ShowProductsList();

	void AddProduct();

	void UpdateProduct();

	void DeleteProduct();

	void ShowUsersList();

	void AddUser();

	void UpdateUser();

	void DeleteUser();

protected:

	ProductContext _productContext;
	UsersContext _userContext;
};