#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string id;
	string name;
	string pass;
	string birthday;
	string gender;

	string role;

public:
	User(string uId, string uName, string uRole);
	virtual ~User() {}

	string getID() const;
	string getName() const;
	string getRole() const;

	bool setName(string n);

	virtual void display() = 0;


	// : check input login
	User(string uId, string uPass, string uName, string uGender, string uBirthday)
        : id(uId), pass(uPass), name(uName), gender(uGender), birthday(uBirthday) {};

	bool checkPassword(const string& inputPass) const;

};
