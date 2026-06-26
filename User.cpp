#include <iostream>
#include <cctype>
#include "User.h"

using namespace std;

User::User(string _uId, string _uPass, string _uName, string _uGender, string _uBirthday)
    : id(_uId), pass(_uPass), name(_uName), gender(_uGender), birthday(_uBirthday)
{
}

string User::getID() const
{
    return id;
}

string User::getName() const
{
    return name;
}

string User::getBirthday() const
{
    return birthday;
}

string User::getGender() const
{
    return gender;
}

bool User::checkPassword(const string& inputPass) const
{
    return pass == inputPass;
}


void User::setName(const string& newName) { this->name = newName; }
void User::setBirthday(const string& newBirthday) { this->birthday = newBirthday; }
void User::setGender(const string& newGender) { this->gender = newGender; }
