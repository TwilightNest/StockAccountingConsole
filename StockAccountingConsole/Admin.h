#include "ProductContext.h"
#include <string>

using namespace std;

class Admin
{
public:
	string Name;

	Admin(string login, string password);

	void ShowProducts();

	void AddProoduct();

	void ChangeProduct();

	void DeleteProduct();

	void ShowUsers();

	void AddUser();

	void ChangeUser();

	void DeleteUser();

private:
	string _password;
	ProductContext _context;

	void Login(string login, string password);
};