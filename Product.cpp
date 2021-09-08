#include "Product.h"
Product::Product(int sellerID, int price, string name, string category)
{
	this->sellerID = sellerID;
	this->price = price;
	this->namepro = name;
	this->category = category;
	this->productID = productNumber + 1;
	productNumber++;
}
void Product::view()
{
	cout << "Name :" << namepro << endl;
	cout << "Category is :" << category << endl;
	cout << "Product ID is :" << productID << endl;
	cout << "Price is : " << price << endl;
	cout << "the seller ID id :" << sellerID << endl;
}

void Product::viewCart()
{
	cout << "Name :" << namepro << endl;
	cout << "Product ID is :" << productID << endl;
	cout << "Price is : " << price << endl;
}


string Product::getnamepro() {
	return namepro;
}

int Product::getPrice() {
	return this->price;
}

int Product::getProductID()
{
	return this->productID;
}

string Product::getCategory()
{
	return this->category;
}