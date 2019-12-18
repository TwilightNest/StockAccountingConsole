#pragma once
#include "ProductContext.h"
#include <string>

using namespace std;

class UserRole
{
public:

	UserRole();

	void ShowProductsList();

	void AddProduct();

	void UpdateProduct();

	void DeleteProduct();

	void SortProduct();

	void SearchProduct();

protected:

	ProductContext _productContext;
};