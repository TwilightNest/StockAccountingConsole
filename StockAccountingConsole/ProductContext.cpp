#include "ProductContext.h"
#include <iostream>
#include <sstream>

ProductContext::ProductContext()
{
	_path = "Products.txt";
	Products = ParseProducts();
}

void ProductContext::ShowProductsList()
{
	cout << endl << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < Products.size(); i++)
	{
		cout << Products[i].Name << "\t"
			<< Products[i].Count << "\t"
			<< Products[i].Price << "\t"
			<< Product::ConvertDateToString(Products[i].Date) << "\t"
			<< Products[i].Fio << "\t" << endl;
	}
	cout << "----------------------------------------------------------------------" << endl;
}

void ProductContext::AddProduct(Product &product)
{
	Products.push_back(product);
	UpdateFile();
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Done!" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void ProductContext::UpdateProduct(string& name)
{
	for (int i = 0; i < Products.size(); ++i)
	{
		if (Products[i].Name == name)
		{
			string tmpDate;
			cout << "Enter new product name: ";
			cin >> Products[i].Name;
			cout << endl << "Enter new count: ";
			cin >> Products[i].Count;
			cout << endl << "Enter new price: ";
			cin >> Products[i].Price;
			cout << endl << "Enter new date(dd::mm::yy): ";
			cin >> tmpDate;
			Products[i].Date = Product::ConvertStringToDate(tmpDate);
			cout << endl << "Enter new FIO: ";
			cin >> Products[i].Fio;
			cout << endl;
			UpdateFile();
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Done!" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			return;
		}
	}
	cout << "----------------------------------------------------------------------" << endl;
	cout << "No such product" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void ProductContext::DeleteProduct(string& name)
{
	auto iter = Products.begin();
	for (int i = 0; i < Products.size(); ++i)
	{
		if (Products[i].Name == name)
		{
			Products.erase(iter);
			UpdateFile();
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Done!" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			return;
		}
		iter++;
	}
	cout << "----------------------------------------------------------------------" << endl;
	cout << "No such product" << endl;
	cout << "----------------------------------------------------------------------" << endl;
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

Product ProductContext::GetProductFromString(string &str)
{
	stringstream ss(str);
	string token;
	vector<string> tmp;
	while (getline(ss, token, '\t'))
	{
		tmp.push_back(token);
	}
	Product product(tmp[0], stoi(tmp[1]), stoi(tmp[2]), Product::ConvertStringToDate(tmp[3]), tmp[4]);
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