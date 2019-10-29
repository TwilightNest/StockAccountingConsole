#include <vector>
#include <fstream>
#include <string>
#include "Product.h"

class ProductContext
{
public:
	vector<Product> Products;

	ProductContext(string path);

	void ShowProductsList();

	void AddProduct(Product product);

	void UpdateProduct(Product product);

	void DeleteProduct(Product product);

private:
	string _path;
	ifstream _is;
	ofstream _os;

	vector<Product> ParseProducts();

	Product GetProductFromString(string str);

	void UpdateFile();
};