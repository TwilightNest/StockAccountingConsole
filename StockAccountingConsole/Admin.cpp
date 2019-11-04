#include "Admin.h"

Admin::Admin(string login, string password) : Role(login, password)
{
	_userContext = UsersContext();
}

void Admin::ShowUsers()
{

}

void Admin::AddUser()
{

}

void Admin::ChangeUser()
{

}

void Admin::DeleteUser()
{

}