#include "ProductContext.h"
#include <string>

using namespace std;

class Role
{
public:
	string Name;

	Role(string login, string password);

	virtual void ShowProducts();

	virtual void AddProoduct();

	virtual void ChangeProduct();

	virtual void DeleteProduct();

protected:
	string _password;
	ProductContext _productContext;
	istream _in;

	void Login(string login, string password);
};