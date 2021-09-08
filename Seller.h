#pragma once
#include "Person.h"
#include "Product.h"
#include <iostream>
#include <vector>
class Seller : public Person
{
public:
	void addProduct(int, vector <Product>&, vector<string>&);
	Seller();
};
