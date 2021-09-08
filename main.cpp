#include "Person.h"
#include <iostream>
#include "Product.h"
#include "Customer.h"
#include <string>
#include <vector>
#include "Seller.h"


using namespace std;

int Person::userNumber = 0;
int Product::productNumber = 0;


int main()
{
	int choise = 0;
	vector<Product>products;
	vector<Product>cart ;
	vector<string> categories;
	vector<pair<vector<Product>, int>>carts;
	string name, category;
	int productid;


	Product pro1 = Product(1, 10, "t.shirt", "clothes");
	Product pro2 = Product(2, 30, "tomato", "food");
	Product pro3 = Product(2, 30, "Eggs", "food");
	Product pro4 = Product(2, 30, "Lan4on", "food");
	Product pro5 = Product(3, 50, "cat", "pets");
	Product pro6 = Product(3, 50, "Dogs", "pets");
	Product pro7 = Product(4, 1500, "mobile", "electronics");


	categories.push_back("clothes");
	categories.push_back("food");
	categories.push_back("pets");
	categories.push_back("electronics");

	products.push_back(pro1);
	products.push_back(pro2);
	products.push_back(pro3);
	products.push_back(pro4);
	products.push_back(pro5);
	products.push_back(pro6);
	products.push_back(pro7);

	string answer;
	string email;
	vector <Person> users;
	while (true) {
		cout << "Do you want to...?\n1-sell\n2-buy" << endl;
		cin >> answer;
		int currentID;
		cout << "Enter your name : ";
		cin >> name;
		cout << endl;
		cout << "Enter your email : ";
		cin >> email;
		cout << endl;


		bool found = false;
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getEmail() == email)
			{
				cout << "Welcome again " << users[i].getName() << endl;
				found = true;
				currentID = users[i].getID();
				cout << currentID;
				break;
			}
		}

		if (!found)
		{
			Person person = Person(name, email);
			currentID = Person::userNumber;
			users.push_back(person);
			cout << "Welcome " << users[currentID - 1].getName() << endl;
		}
		if (answer == "sell" || answer == "Sell" || answer == "1")
		{
			Seller seller;

			while (true) {
				int choise;

				cout << "Which thing do u wanna do(please enter a number)?\n";
				cout << "1-Add product.\n";
				cout << "2-Logout.\n";
				cout << "3-Exit the program.\n";
				cin >> choise;

				if (choise == 1)
				{
					seller.addProduct(currentID, products, categories);
				}
				else if (choise == 2) {
					break;
				}
				else if (choise == 3) {
					return 0;
				}
				else {
					cout << "Please Enter a number from the menu.\n";
				}
			}
		}
		else if (answer == "buy" || answer == "Buy" || answer == "2")
		{
			Customer cust = Customer();
			choise = 6;
			while (choise != 0) {
				cout << "do you want to view products (press 1)\n";
				cout << "do you want to search by name (press 2)\n";
				cout << "do you want to search by category (press 3)\n";
				cout << "do you want to add to cart  (press 4)\n";
				cout << "do you want to confirm buying (press 5)\n";
				cout << "press 6 to logout\n";
				cin >> choise;
				if (choise == 1) {
					for (int i = 0; i < categories.size(); i++) {
						cout << categories[i] << endl;
						cout << "_______" << endl;
						for (int j = 0; j < products.size(); j++) {
							if (categories[i] == products[j].getCategory()) {
								products[j].view();
								cout << "************************* \n";
							}
						}
					}
				}
				else if (choise == 2) {
					cin >> name;
					cust.searchbyname(products, name);
				}

				else if (choise == 3) {
					cin >> category;
					cust.searchbycategory(products, category);
				}
				else if (choise == 4) {
					cout << "Enter Product ID or enter -1 to out\n";
					cin >> productid;
					do {
						cust.Addtocart(products, productid, carts, currentID);
						cin >> productid;
					} while (productid != -1);

				}
				else if (choise == 5) {
					cust.confirmbyuing(currentID, carts);
				}

			}
		}

	}

	return 0;
}