#include "UsersContext.h"
#include <iostream>
#include <sstream>

UsersContext::UsersContext()
{
	_path = "Users.txt";
	Users = ParseUsers();
}

void UsersContext::ShowUsersList()
{
	cout << endl << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < Users.size(); ++i)
	{
		cout << Users[i].Login << "\t"
			<< Users[i].Name << "\t"
			<< Users[i].Password << "\t"
			<< Users[i].IsAdmin << "\t" << endl;
	}
	cout << "----------------------------------------------------------------------" << endl;
}

void UsersContext::AddUser(User& user)
{
	Users.push_back(user);
	UpdateFile();
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Done!" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void UsersContext::UpdateUser(string& name)
{
	for (int i = 0; i < Users.size(); ++i)
	{
		if (Users[i].Name == name)
		{
			string tmpDate;
			cout << "Enter new login: ";
			cin >> Users[i].Login;
			cout << endl << "Enter new name: ";
			cin >> Users[i].Name;
			cout << endl << "Enter new password: ";
			cin >> Users[i].Password;
			cout << endl << "Enter new role(1- Administrator, 0 - User): ";
			cin >> Users[i].IsAdmin;
			cout << endl;
			UpdateFile();
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Done!" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			return;
		}
	}
	cout << "----------------------------------------------------------------------" << endl;
	cout << "No such user" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void UsersContext::DeleteUser(string& name)
{
	auto iter = Users.begin();
	for (int i = 0; i < Users.size(); ++i)
	{
		if (Users[i].Name == name)
		{
			Users.erase(iter);
			UpdateFile();
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Done!" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			return;
		}
		iter++;
	}
	cout << "----------------------------------------------------------------------" << endl;
	cout << "No such user" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

vector<User> UsersContext::ParseUsers()
{
	auto users = vector<User>();
	_is.open(_path, ios_base::in);
	string str;
	while (getline(_is, str))
	{
		users.push_back(GetUserFromString(str));
	}
	_is.close();
	return users;
}

User UsersContext::GetUserFromString(string& str)
{
	stringstream ss(str);
	string token;
	vector<string> tmp;
	while (getline(ss, token, '\t'))
	{
		tmp.push_back(token);
	}
	User user(tmp[0], tmp[1], tmp[2], tmp[3]);
	return user;
}

void UsersContext::UpdateFile()
{
	_os.open(_path, ios::out);
	for (int i = 0; i < Users.size(); i++)
	{
		_os << Users[i].Login << "\t"
			<< Users[i].Name << "\t"
			<< Users[i].Password << "\t"
			<< Users[i].IsAdmin << endl;
	}
	_os.close();
}