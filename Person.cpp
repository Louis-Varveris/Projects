#include<iostream>
#include<vector>
#include<string>
#include"Person.h"
using namespace std;

//fills the constructor.
Person::Person() 
{
	lastName = "Na";
	firstName = "Na";
	phoneNumber = "Na";
};
Person::Person(const string& LastName, const string& FirstName, const string& PhoneNumber) 
{
	lastName = LastName;
	firstName = FirstName;
	phoneNumber = PhoneNumber; 
};
//fills the getters.
string Person::getLastName()const
{
	return lastName;
};
string Person::getFirstName()const
{
	return firstName; 
};
string Person::getPhoneNumber()const
{
	return phoneNumber;
};
//fills the setters.
void Person::setLastName(string& last)
{
	lastName = last;
};
void Person::setFirstName(string& first)
{
	firstName = first;
};
void Person::setPhoneNumber(string& phone)
{
	phoneNumber = phone;
};
//fills in the display.
void Person::display()const
{
	cout << "What is your Name: \n" << firstName << " " << lastName << "\n";
	cout << "What is your Phonenumber: \n" << phoneNumber << "\n";
};
