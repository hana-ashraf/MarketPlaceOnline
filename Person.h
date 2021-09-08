#pragma once
#include<iostream>
#include <string>

using namespace std;
class Person
{
private:
	int ID;
	string name;
	string Email;

public:
	static int userNumber;
	Person();
	Person(string, string);
	int getID();
	string getEmail();
	string getName();
};
