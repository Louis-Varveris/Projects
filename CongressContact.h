#include<iostream>
#include<vector>
#include<string>
#include"Person.h"
using namespace std;
#ifndef CONGRESSCONTACT_H
#define CONGRESSCONTACT_H
class CongressContact
{
public:
    //Makes a default constructor.
    CongressContact();
    //Makes a copy constructor.
    CongressContact(const string& last_name, const string& first_name, const string& middle_name, const string& suffix, const string& nickname, const string& full_name, const string& birthday, const string& gender, const string& type, const string& state, const string& district, const string& senate_class, const string& party, const string& url, const string& address, const string& phone);
    //Displays the Getters:
    string getLastName()const;
    string getFirstName()const;
    string getPhoneNumber()const;
    bool operator<(const CongressContact& LN)const; 
    bool operator==(const CongressContact& other)const;
    //Makes the display.
    void display()const;
    //Makes the ofstream operator for Congress Contact.
    friend ostream& operator<<(ostream& out, const CongressContact& person);
private:
    //Makes the strings for all the categories.
    string lastName;
    string firstName;
    string middleName;
    string suffix;
    string nickname;
    string fullName;
    string birthday;
    string gender;
    string type;
    string state;
    string district;
    string senateClass;
    string party;
    string url;
    string address;
    string phoneNumber;
};
#endif

