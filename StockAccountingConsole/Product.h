#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Product
{
public:
	string Name;
	int Count;
	int Price;
	tm Date;
	string Fio;

	Product()
	{

	}

	Product(string name, int count, int price, tm date, string fio)
	{
		Name = name;
		Count = count;
		Price = price;
		Date = date;
		Fio = fio;
	}

	static string ConvertDateToString(tm date)
	{
		string day(to_string(date.tm_mday));
		string month(to_string(date.tm_mon));
		string year(to_string(date.tm_year));
		return day + "." + month + "." + year;
	}

	static tm ConvertStringToDate(string date)
	{
		tm tm;
		stringstream ss(date);
		string token;
		vector<string> tmp;
		while (getline(ss, token, '.'))
		{
			tmp.push_back(token);
		}
		tm.tm_mday = stoi(tmp[0]);
		tm.tm_mon = stoi(tmp[1]);
		tm.tm_year = stoi(tmp[2]);
		return tm;
	}
};