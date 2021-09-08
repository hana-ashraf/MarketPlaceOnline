#pragma once
#include <string>
#include <iostream>
using namespace std;
class Product
{
private:
	int productID;
	int sellerID;
	int price;
	string namepro;
	string category;

public:
	static int productNumber;
	Product(int, int, string, string);
	void view();
	void viewCart();
	string getnamepro();
	int getPrice();
	int getProductID();
	string getCategory();
};
