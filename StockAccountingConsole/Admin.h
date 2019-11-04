#include "Role.h"
#include "UsersContext.h"
#include <string>

using namespace std;

class Admin : public Role
{
public:

	Admin(string login, string password);

	void ShowUsers();

	void AddUser();

	void ChangeUser();

	void DeleteUser();

protected:
	UsersContext _userContext;
};