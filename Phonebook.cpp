#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
#include"Phonebook.h"
using namespace std;
//fills the PhoneBook constructor.
PhoneBook::PhoneBook() : Contacts(), numcontacts(0), Capacity(20) 
{
	Contacts = new Person[Capacity]; 
};
//fills in the Copy PhoneBook constructor.
PhoneBook::PhoneBook(const PhoneBook& another) : numcontacts(another.numcontacts), Capacity(another.Capacity)
{
	Contacts = new Person[Capacity];
	for (int i = 0; i < Capacity; i++)
	{
		Contacts[i] = another.Contacts[i];
	}
};
//fills the destructor.
PhoneBook::~PhoneBook()
{
	delete[] Contacts; 
	cout << "Contact has been removed." << endl;
}
//fills the PhoneBook add.
void PhoneBook::add(const CongressContact& congressContact) 
{
	
	if (contacts.size() < Capacity) 
	{
		contacts.push_back(congressContact); 
	}
	else 
	{
		
	}
};
//fills in the PhoneBook display.
void PhoneBook::display()const 
{
	for (const auto& contact : contacts)  
	{
		contact.display(); 
	}
}
//fills in the Congress Contact search function.
CongressContact PhoneBook::search(const string& PhoneNumber)const   
{ 
	for (const auto& contact : contacts) 
	{
		if (contact.getPhoneNumber() == PhoneNumber) 
		{
			return contact; 
		}
	}
	return CongressContact(); 
};
//fills in the edit function.
void PhoneBook::edit(string& phoneNumber, string& newfirstName, string& newlastName)
{
	for (int i = 0; i < numcontacts; i++)
	{
		if (Contacts[i].getPhoneNumber() == phoneNumber)
		{
			Contacts[i].setFirstName(newfirstName);
			Contacts[i].setLastName(newlastName);
			cout << "The Phone Number has been updated. \n" << phoneNumber << "\n";
			return;
		}
	}
};
//fills in the provecopy function.
void PhoneBook::proveTheCopy() const
{
	PhoneBook copy(*this);
	cout << "The copied PhoneBook contents are as follows: \n";
	copy.display();
};
//fills in the overloaded assignment operator.
PhoneBook& PhoneBook::operator=(const PhoneBook& next) 
{
	if (this != &next) 
	{
		delete[] Contacts; 
		numcontacts = next.numcontacts; 
		Capacity = next.Capacity;  
		Contacts = new Person[Capacity]; 
		for (int i = 0; i < numcontacts; i++) 
		{
			Contacts[i] = next.Contacts[i]; 
		}
	}
	return *this;
};
//fills in the bubblesort phonenumber contacts function.
void PhoneBook::SortContactsPhoneNumber()
{
	sort(contacts.begin(), contacts.end(), [](const CongressContact& a, const CongressContact& b) 
		{
			return a.getPhoneNumber() < b.getPhoneNumber(); 
		}); 
};
//fills in the templeted binary search.
template<typename T>
const T* PhoneBook::BinarySearch(const vector<T>& sortedList, int left, int right, const string& key)const
{
	if (left > right) 
	{
		return nullptr; 
	}
	int mid = left + (right - left) / 2;
	const T& midElement = sortedList[mid]; 
	if (midElement.getPhoneNumber() == key) 
	{
		return &midElement;
	}
	else if (midElement.getPhoneNumber() < key) 
	{
		return BinarySearch(sortedList, mid + 1, right, key); 
	}
	else 
	{
		return BinarySearch(sortedList, left, mid - 1, key); 
	}
};
//fills in the overloaded operators.
bool PhoneBook::operator==(const PhoneBook& another)const
{
	if (contacts.size() != another.contacts.size()) 
	{
		return false;
	}
	for (size_t i = 0; i < contacts.size(); i++) 
	{
		if (!(contacts[i] == another.contacts[i])) 
		{
			return false;
		}
	}
	return true;
};
bool PhoneBook::operator<(const PhoneBook& another)const
{
	return lexicographical_compare(another.contacts.begin(), another.contacts.end(),
		contacts.begin(), contacts.end()); 
};
bool PhoneBook::operator>=(const PhoneBook& another)const
{
	return !(*this < another); 
};
bool PhoneBook::operator>(const PhoneBook& another)const
{
	return lexicographical_compare(contacts.begin(), contacts.end(), 
		another.contacts.begin(), another.contacts.end()); 
}
bool PhoneBook::operator<=(const PhoneBook& another)const
{
	return !(*this > another);
};
ostream& operator<<(ostream& out, const PhoneBook& contact) 
{
	for (int i = 0; i < contact.numcontacts; i++) 
	{
		out << "The contact of the Congress Member is: " << i + 1 << endl;
		out << "Congress Members last name is: " << contact.Contacts[i].getLastName() << endl;
		out << "Congress Members first name is: " << contact.Contacts[i].getFirstName() << endl;
		out << "Congress Members phonenumber is: " << contact.Contacts[i].getPhoneNumber() << endl;
	}
	return out;
};
