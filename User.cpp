#include <iostream>
#include <cctype>
#include "User.h"

using namespace std;

User::User(string uId, string uPass, string uName, string uGender, string uBirthday)
    : id(uId), pass(uPass), name(uName), gender(uGender), birthday(uBirthday)
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
