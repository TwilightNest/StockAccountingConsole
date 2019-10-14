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

	static string ConvertDateToString(tm date)
	{
		string day(to_string(date.tm_mday));
		string month(to_string(date.tm_mon));
		string year(to_string(date.tm_year));
		return day + "." + month + "." + year;
	}
};