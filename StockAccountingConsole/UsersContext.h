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

private:
	string _path;
	ifstream _is;
	ofstream _os;

	vector<User> ParseUsers();

	User GetUserFromString(string &str);

	void UpdateFile();
};