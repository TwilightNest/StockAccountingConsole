#include <fstream>

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

	void Write(string message)
	{
		_outputFileStream.open(_path, ios::app);
		_outputFileStream << message;
		_outputFileStream.close();
	}
};