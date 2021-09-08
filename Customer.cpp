#pragma once
#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer() {

}

void Customer::searchbyname(vector<Product>& products, string name) {
	bool found = false;

	for (size_t i = 0; i < products.size(); i++) {
		if (products[i].getnamepro() == name) {
			products[i].view();
			cout << "    ******************   " << endl;
			found = true;
		}
	}
	if (found == false) {
		cout << " NO match found ";
	}


}
void Customer::searchbycategory(vector<Product>& products, string category) {
	bool found = false;

	for (size_t i = 0; i < products.size(); i++) {
		if (products[i].getCategory() == category) {
			products[i].view();
			cout << "    ******************   " << endl;
			found = true;
		}
	}
	if (found == false) {
		cout << " NO match found \n";
	}
}


void Customer::Addtocart(vector<Product>& products, int productid, vector<pair<vector<Product>, int>>& allCarts, int id)
{

	int counter = 0;
	bool found = false;
	carts.clear();
	carts.push_back(products[productid - 1]);
	cout << "Product is added successfully\n";
	if (allCarts.empty()) {
		allCarts.push_back({ carts,id });
	}
	else {
		for (int i = 0; i < allCarts.size(); i++) {
			if (allCarts[i].second == id) {
				found = true;			
				allCarts[i].first.push_back(carts[0]);
				carts.clear();								
				break;
			}

		}

		if (!found) {
			allCarts.push_back({ carts,id });
		}
	}
}

void Customer::confirmbyuing(int id, vector<pair<vector<Product>, int>>& allCarts)
{
	int total_price = 0;
	string answer;
	string address;
	int phone;
	cout << "Enter your address : " << endl;
	cin >> address;
	cout << "Enter your phone : " << endl;
	cin >> phone;
	for (int i = 0; i < allCarts.size(); i++) {
		if (allCarts[i].second == id) {
			for (int j = 0; j < allCarts[i].first.size(); j++)
			{
				allCarts[i].first[j].viewCart();
				total_price += allCarts[i].first[j].getPrice();
			}
		}
	}
	cout << endl;
	cout << "    ------------------     " << endl;
	cout << "Total Price : " << total_price << endl;
	cout << "    ------------------     " << endl;
	cout << endl;
	cout << "Do You Want To Confirm Purchasing ?" << endl;
	cin >> answer;
	if (answer == "yes" || answer == "Yes" || answer == "y") {
		cout << "Thanks For Purchasing. Products will be delivered to " << address << endl;
	}


}