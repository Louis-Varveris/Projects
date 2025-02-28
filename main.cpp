#include<iostream>
#include<vector>
#include<string>
#include<fstream> 
#include"Person.h"
#include"Phonebook.h"
#include"CongressContact.h"
using namespace std;
string ToLowercase(string strin) 
{
    string result;
    for (char c : strin) 
    { 
        result += tolower(c); 
    }
    return result;
}
int main()
{
    PhoneBook phoneobjects;
    //Checks if the file opened correctly.
    ifstream InFile("CongressContacts.txt");
    if (!InFile) 
    {
        cout << "Could not open." << endl;
        return 1;
    }
    //Gets all the info for each Congress Member.
    string Line; 
    while (getline(InFile, Line)) 
    { 
        string lastName, firstName, middleName, suffix, nickname, fullName, birthday, 
            gender, type, state, district, senateClass, party, url, address, phoneNumber;
        getline(InFile, lastName, ','); 
        getline(InFile, firstName, ','); 
        getline(InFile, middleName, ','); 
        getline(InFile, suffix, ','); 
        getline(InFile, nickname, ','); 
        getline(InFile, fullName, ','); 
        getline(InFile, birthday, ','); 
        getline(InFile, gender, ',');
        getline(InFile, type, ',');
        getline(InFile, state, ',');
        getline(InFile, district, ',');
        getline(InFile, senateClass, ',');
        getline(InFile, party, ',');
        getline(InFile, url, ',');
        getline(InFile, address, ',');
        getline(InFile, phoneNumber, ',');
        CongressContact contact(lastName, firstName, middleName, suffix, nickname, fullName, 
            birthday, gender, type, state, district, senateClass, party,
            url, address, phoneNumber);
        phoneobjects.add(contact);  
    } 
    InFile.close();  
	string answer; 
    while (true) 
    {
        cout << "Display the PhoneBook: \n";
        cout << "Add a Person: \n";
        cout << "Search for a Phone Number: \n";
        cout << "Edit a Person: \n";
        cout << "Prove Copy: \n";
        cout << "Prove Assignment: \n";
        cout << "Exit\n";
        cout << "Input a choice: ";
        getline(cin, answer); 
        string lowercaseAnswer = ToLowercase(answer);  
        {
            if (lowercaseAnswer == "display") 
            {
               phoneobjects.display(); 
            }
            else if (lowercaseAnswer == "add") 
            {
                string lastName, firstName, phoneNumber; 
                cout << "Enter the Last Name: "; 
                getline(cin, lastName); 
                cout << "Enter the First Name: "; 
                getline(cin, firstName); 
                cout << "Enter the Phone Number: "; 
                getline(cin, phoneNumber); 
                CongressContact newContact(lastName, firstName, "", "", "", lastName + " " + firstName, "", "", "", "", "", "", "", "", "", phoneNumber); 
                phoneobjects.add(newContact); 
            }
            else if (lowercaseAnswer == "search") 
            {
                string phoneNumberToSearch; 
                cout << "Enter the phone number to search: ";
                getline(cin, phoneNumberToSearch); 
                CongressContact foundContact = phoneobjects.search(phoneNumberToSearch); 
                if (foundContact.getLastName() != "") 
                { 
                    cout << "Contact found:" << endl; 
                    foundContact.display(); 
                }
                else 
                {
                    cout << "Contact not found." << endl; 
                }
            } 
            else if (lowercaseAnswer == "edit") 
            {
                string phoneNumber, newFirstName, newLastName; 
                cout << "Enter the Phone Number of the person you want to edit: "; 
                getline(cin, phoneNumber); 
                cout << "Enter the new First Name: "; 
                getline(cin, newFirstName); 
                cout << "Enter the new Last Name: "; 
                getline(cin, newLastName); 
                phoneobjects.edit(phoneNumber, newFirstName, newLastName); 
            }
            else if (lowercaseAnswer == "prove the copy") 
            {
                phoneobjects.proveTheCopy(); 
            }
            else if (lowercaseAnswer == "prove the assignment")
            {
                PhoneBook copyofPhoneBook;
                copyofPhoneBook = phoneobjects;
                cout << "The PhoneBook contents that have been copied are: ";
                copyofPhoneBook.display(); 
            }
            else if (lowercaseAnswer == "exit") 
            {
                break;
            }
            else
            {
                cout << "No input.";
            }
        }
    }
    InFile.close(); 

	return 0;
}
