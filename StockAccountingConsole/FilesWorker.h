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
		_inputFileStream.open(_path, ios_base::in);
		string str;
		string delimiter = "\t";
		string token;
		size_t pos;
		while (!_inputFileStream.eof())
		{
			getline(_inputFileStream, str);
			while (pos = str.find(delimiter) != string::npos)
			{
				token = str.substr(0, pos);
				cout << token;
				str.erase(0, pos + delimiter.length());
			}
			cout << str  << " | " << endl;
		}
	}

	void WriteProduct(Product product)
	{
		_outputFileStream.open(_path, ios::app);
		_outputFileStream << product.Name << "\t" << product.Count << "\t" << product.Price << "\t" << Product::ConvertDateToString(product.Date) << "\t" << product.Fio << endl;
		_outputFileStream.close();
	}
};