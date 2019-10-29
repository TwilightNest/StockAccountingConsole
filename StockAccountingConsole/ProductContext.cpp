#include "ProductContext.h"
#include <iostream>
#include <sstream>

ProductContext::ProductContext(string path)
{
	_path = path;
	Products = ParseProducts();
}

void ProductContext::ShowProductsList()
{
	for (int i = 0; i < Products.size(); i++)
	{
		cout << Products[i].Name << "\t" << Products[i].Count << "\t" << Products[i].Price << "\t" << Product::ConvertDateToString(Products[i].Date) << "\t" << Products[i].Fio << "\t" << endl;
	}
}

void ProductContext::AddProduct(Product product)
{
	Products.push_back(product);
	UpdateFile();
}

void ProductContext::UpdateProduct(Product product)
{
	UpdateFile();
}

void ProductContext::DeleteProduct(Product product)
{
	UpdateFile();
}

vector<Product> ProductContext::ParseProducts()
{
	auto products = vector<Product>();
	_is.open(_path, ios_base::in);
	string str;
	while (getline(_is, str))
	{
		products.push_back(GetProductFromString(str));
	}
	_is.close();
	return products;
}

Product ProductContext::GetProductFromString(string str)
{
	auto product = Product();
	stringstream ss(str);
	string token;
	vector<string> tmp;
	while (getline(ss, token, '\t'))
	{
		tmp.push_back(token);
	}
	product.Name = tmp[0];
	product.Count = stoi(tmp[1]);
	product.Price = stoi(tmp[2]);
	product.Date = Product::ConvertStringToDate(tmp[3]);
	product.Fio = tmp[4];
	return product;
}

void ProductContext::UpdateFile()
{
	_os.open(_path, ios::out);
	for (int i = 0; i < Products.size(); i++)
	{
		_os << Products[i].Name << "\t" << Products[i].Count << "\t" << Products[i].Price << "\t" << Product::ConvertDateToString(Products[i].Date) << "\t" << Products[i].Fio << endl;
	}
	_os.close();
}