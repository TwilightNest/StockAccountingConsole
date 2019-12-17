#include "User.h"
#include <vector>
#include <sstream>

using namespace std;

User::User(string login, string name, string password, string isAdmin)
{
	Login = login;
	Name = name;
	Password = password;
	IsAdmin = isAdmin;
}