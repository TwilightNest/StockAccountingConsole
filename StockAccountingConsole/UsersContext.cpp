#include "UsersContext.h"
#include <iostream>
#include <sstream>
#include <algorithm>

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

vector<User*> UsersContext::ConvertToPointers()
{
	auto result = new vector<User*>;
	for (int i = 0; i < Users.size(); ++i)
	{
		result->push_back(&Users[i]);
	}
	return *result;
}

void UsersContext::SortUser(int& sortBy)
{
	struct compareByLogin {
		bool operator()(User* a, User* b) {
			return a->Login < b->Login;
		}
	};

	struct compareByName {
		bool operator()(User* a, User* b) {
			return a->Name < b->Name;
		}
	};

	struct compareByAdmin {
		bool operator()(User* a, User* b) {
			return a->IsAdmin < b->IsAdmin;
		}
	};
	auto tmp = ConvertToPointers();
	switch (sortBy)
	{
	case 1:
	{
		sort(tmp.begin(), tmp.end(), compareByLogin());
		break;
	}
	case 2:
	{
		sort(tmp.begin(), tmp.end(), compareByName());
		break;
	}
	case 3:
	{
		sort(tmp.begin(), tmp.end(), compareByAdmin());
		break;
	}
	default:
		cout << "----------------------------------------------------------------------" << endl;
		cout << "Invalid choise" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		return;
	}
	cout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < tmp.size(); ++i)
	{
		cout << tmp[i]->Login << "\t"
			<< tmp[i]->Name << "\t"
			<< tmp[i]->Password << "\t"
			<< tmp[i]->IsAdmin << endl;
	}
	cout << "----------------------------------------------------------------------" << endl;
}

void UsersContext::SearchUser(string& str, int& searchBy)
{
	cout << "----------------------------------------------------------------------" << endl;
	switch (searchBy)
	{
	case 1:
	{
		for (int i = 0; i < Users.size(); ++i)
		{
			if (Users[i].Login == str)
				cout << UsersContext::GetStringFromUser(Users[i]);
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < Users.size(); ++i)
		{
			if (Users[i].Name == str)
				cout << UsersContext::GetStringFromUser(Users[i]);
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < Users.size(); ++i)
		{
			if (Users[i].IsAdmin == str)
				cout << UsersContext::GetStringFromUser(Users[i]);
		}
		break;
	}
	default:
	{
		cout << "----------------------------------------------------------------------" << endl;
		cout << "Invalid choise" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		return;
	}
	}
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

string UsersContext::GetStringFromUser(User& user)
{
	string tmp = user.Login + "\t"
		+ user.Name + "\t"
		+ user.Password + "\t"
		+ user.IsAdmin + "\n";
	return tmp;
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