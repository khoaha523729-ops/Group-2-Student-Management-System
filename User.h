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
    string birthday;
    string gender;

public:
    User(string uId, string uPass, string uName, string uGender, string uBirthday);

    virtual ~User() = default;

    string getID() const;
    string getName() const;
    string getBirthday() const;
    string getGender() const;

    bool checkPassword(const string& inputPass) const;

    virtual void display(Database& db){};

    //lay du lieu cho admin
    void setName(const string& newName) ;
    void setBirthday(const string& newBirthday) ;
    void setGender(const string& newGender);
};
