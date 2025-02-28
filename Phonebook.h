#include<iostream>
#include<vector>
#include<string>
#include"Person.h"
#include"CongressContact.h" 
using namespace std;
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
class PhoneBook
{
    public:
    //Makes a default constructor.
    PhoneBook();
    //Makes a copy constrcutor.
    PhoneBook(const PhoneBook& another); 
    //Makes a destructor.
    ~PhoneBook();
    //Displays Person obejcts.
    void display()const;
    //Adds a Person object.
    void add(const CongressContact& congressContact);
    //Adds a Congress Contact search function.
    CongressContact search(const string& phoneNumber) const; 
    //Makes a bubblesort function for phonenumber.
    void SortContactsPhoneNumber(); 
    //Makes the templated binary search.
    template<typename T>
    const T* BinarySearch(const vector<T>& sortedList, int left, int right, const string& key)const; 
    //Makes the overloaded operators for phonebook.
    bool operator==(const PhoneBook& another) const;
    bool operator<(const PhoneBook& another) const;
    bool operator>=(const PhoneBook& another) const;
    bool operator>(const PhoneBook& another)const;
    bool operator<=(const PhoneBook& another) const;
    friend ostream& operator<<(ostream& out, const PhoneBook& Contact); 
    //Adds a edit function. 
    void edit(string& phoneNumber,string& newfirstName,string& newlastName);
    //Adds a provecopy function.
    void proveTheCopy() const;
    //Adds a overloaded assignment operator.
    PhoneBook& operator=(const PhoneBook& next);
    private:
    //Makes the dynamic array.
    Person* Contacts; 
    int numcontacts;
    int Capacity; 
    //Makes the vector for Congress Contacts.
    vector<CongressContact> contacts;
};
#endif

