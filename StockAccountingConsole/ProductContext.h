#pragma once
#include "Product.h"
#include <vector>
#include <fstream>

class ProductContext
{
public:
	vector<Product> Products;

	ProductContext();

	void ShowProductsList();

	void AddProduct(Product &product);

	void UpdateProduct(string &name);

	void DeleteProduct(string &name);

private:
	string _path;
	ifstream _is;
	ofstream _os;

	vector<Product> ParseProducts();

	Product GetProductFromString(string &str);

	void UpdateFile();
};