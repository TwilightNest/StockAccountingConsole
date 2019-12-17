#pragma once
#include <string>

using namespace std;

class Product
{
public:
	string Name;
	int Count;
	int Price;
	tm Date;
	string Fio;

	Product(string name, int count, int price, tm date, string fio);

	static string ConvertDateToString(tm date);

	static tm ConvertStringToDate(string date);
};