#include "Person.h"
Person::Person()
{}
Person::Person(string name, string email)
{
	this->name = name;
	this->Email = email;
	this->ID = userNumber + 1;
	userNumber += 1;
}
int Person::getID()
{
	return ID;
}
string Person::getEmail()
{
	return Email;
}
string Person::getName()
{
	return name;
}