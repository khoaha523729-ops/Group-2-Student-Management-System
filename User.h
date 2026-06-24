#pragma once
#include <string>

using namespace std;

class User
{
protected:
    string id;
    string pass;
    string name;
    string role;
    string birthday;
    string gender;

public:
    User(string uId, string uPass, string uName, string uRole,  string uGender, string uBirthday);

    virtual ~User() = default;

    string getID() const;
    string getName() const;
    string getRole() const;
    string getBirthday() const;
    string getGender() const;

    bool checkPassword(const string& inputPass) const;

    virtual void displayMenu() = 0;
};
