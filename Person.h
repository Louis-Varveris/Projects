#include<iostream>
#include<vector>
#include<string>
using namespace std;
#ifndef PERSON_H
#define PERSON_H
class Person
{
    public:
    Person(); 
    Person(const string& LastName, const string& FirstName, const string& PhoneNumber);
    //Displays the Getters:
    string getLastName()const; 
    string getFirstName()const;
    string getPhoneNumber()const;
    //Displays the Setters:
    void setLastName(string& last);
    void setFirstName(string& first);
    void setPhoneNumber(string& phone);
    //Displays the output:
    void display()const;
    private:
    string lastName;
    string firstName;
    string phoneNumber;
};
#endif
