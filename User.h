#pragma once
#include <string>

class Database;

using namespace std;

class User
{
protected:
    string id;
    string pass;
    string name;
    string gender;
    string birthday;

public:
    User(string uId, string uPass, string uName, string uGender, string uBirthday);


    string getID() const;
    string getName() const;
    string getPass() const;
    string getBirthday() const;
    string getGender() const;

    void setName(string new_name);
    void setGender(string new_gender);
    void setBirthday(string new_birthday);

    bool checkPassword(const string& inputPass) const;

    virtual void display(Database& db) = 0;

};
