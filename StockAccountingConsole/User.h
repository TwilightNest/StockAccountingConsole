#pragma once
#include <string>

using namespace std;

class User
{
public:
	string Login;
	string Name;
	string Password;
	string IsAdmin;

	User(string login, string name, string password, string isAdmin);
};