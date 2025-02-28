#include<iostream>
#include<vector>
#include<string>
#include"CongressContact.h"
using namespace std;
//fills in the default constructor for Congress Contact.
CongressContact::CongressContact()
{

};
//fills in the copy constructor for Congress Contact.
CongressContact::CongressContact(const string& last_name, const string& first_name, const string& middle_name, const string& suffix, const string& nickname, const string& full_name, const string& birthday, const string& gender, const string& type, const string& state, const string& district, const string& senate_class, const string& party, const string& url, const string& address, const string& phone) : lastName(last_name), firstName(first_name), middleName(middle_name), suffix(suffix), nickname(nickname), fullName(full_name), birthday(birthday), gender(gender), type(type), state(state), district(district), senateClass(senate_class), party(party), url(url), address(address), phoneNumber(phone)
{

};
//fills in the getters.
string CongressContact::getLastName()const
{
    return lastName;
};
string CongressContact::getFirstName()const
{
    return firstName;
};
string CongressContact::getPhoneNumber()const
{
    return phoneNumber;
};
bool CongressContact::operator<(const CongressContact& LN)const
{
    return lastName < LN.lastName;  
};
bool CongressContact::operator==(const CongressContact& other)const
{
    return (lastName == other.lastName &&
        firstName == other.firstName &&
        middleName == other.middleName &&
        suffix == other.suffix &&
        nickname == other.nickname &&
        fullName == other.fullName &&
        birthday == other.birthday &&
        gender == other.gender &&
        type == other.type &&
        state == other.state &&
        district == other.district &&
        senateClass == other.senateClass &&
        party == other.party &&
        url == other.url &&
        address == other.address &&
        phoneNumber == other.phoneNumber);
};
//fills in the display for Congress Contact.
void CongressContact::display()const
{
    cout << "The Congress Memeber's name is: " << fullName << " and their phonenumber is: " << phoneNumber << endl;
};
//fills in the ofstream operator for Congress Contact.
ostream& operator<<(ostream& out, const CongressContact& person)  
{
    out << person.lastName << ',' << person.firstName << ',' << person.middleName << ',' 
        << person.suffix << ',' << person.nickname << ',' << person.fullName << ',' 
        << person.birthday << ',' << person.gender << ',' << person.type << ',' 
        << person.state << ',' << person.district << ',' << person.senateClass << ',' 
        << person.party << ',' << person.url << ',' << person.address << ',' 
        << person.phoneNumber; 
    return out;
};
