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

string User::getPass() const
{
    return pass;
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

void User::setName(string new_name) {
    name = new_name;
}

void User::setGender(string new_gender) {
    gender = new_gender;
}

void User::setBirthday(string new_birthday) {
    birthday = new_birthday;
}