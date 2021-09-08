#include "Seller.h"
Seller::Seller()
{

}
void Seller::addProduct(int currentID, vector <Product>& products, vector<string>& categories)
{
	string productName;
	string productCategory;
	int price;
	cout << "Enter the product name : ";
	cin >> productName;
	cout << "Enter the product category : ";
	cin >> productCategory;
	bool found = false;
	for (int i = 0; i < categories.size(); i++) {
		if (productCategory == categories[i]) {
			found = true;
			break;
		}
	}
	if (!found) {
		categories.push_back(productCategory);
	}

	cout << "Enter the product price : ";
	cin >> price;
	Product product = Product(currentID, price, productName, productCategory);
	products.push_back(product);
	product.view();
}