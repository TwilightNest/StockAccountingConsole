#include <iostream>
#include <fstream>
#include <array>
#include "Product.h"

using namespace std;

class FilesWorker
{
public:
	string _path;
	ifstream _inputFileStream;
	ofstream _outputFileStream;

	FilesWorker(string path)
	{
		_path = path;
	}

	void GetProductsList()
	{
		_inputFileStream.open(_path, ios::in);
		string str;
		string delimiter = "\t";
		size_t pos = 0;
		string token;

		printf("|%10s|%10s|%10s|%10s|%10s|\n", "Name", "Count", "Price", "Date", "FIO");
		while (!_inputFileStream.eof())
		{
			getline(_inputFileStream, str);
			printf("|");
			while ((pos = str.find(delimiter)) != string::npos)
			{
				token = str.substr(0, pos);
				printf("%10s|", token);
				str.erase(0, pos + delimiter.length());
			}
			printf("\n");
		}
		_inputFileStream.close();
	}

	void WriteProduct(Product product)
	{
		_outputFileStream.open(_path, ios::app);
		_outputFileStream << product.Name << "\t" << product.Count << "\t" << product.Price << "\t" << Product::ConvertDateToString(product.Date) << "\t" << product.Fio << endl;
		_outputFileStream.close();
	}
};