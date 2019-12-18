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

	void SortProduct();

	void SearchProduct();

	void ShowUsersList();

	void AddUser();

	void UpdateUser();

	void DeleteUser();

	void SortUser();

	void SearchUser();

	void IndividualTask();

protected:

	ProductContext _productContext;
	UsersContext _userContext;
};