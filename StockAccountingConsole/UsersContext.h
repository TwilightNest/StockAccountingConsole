#pragma once
#include "User.h"
#include <vector>
#include <fstream>

class UsersContext
{
public:

	vector<User> Users;

	UsersContext();

	void ShowUsersList();
	
	void AddUser(User &user);

	void UpdateUser(string& name);

	void DeleteUser(string& name);
	
	vector<User*> ConvertToPointers();

	void SortUser(int& sortBy);

	void SearchUser(string& str, int& searchBy);

private:
	string _path;
	ifstream _is;
	ofstream _os;

	vector<User> ParseUsers();

	User GetUserFromString(string &str);

	string GetStringFromUser(User& user);

	void UpdateFile();
};