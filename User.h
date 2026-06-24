#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string id;
	string name;
	string pass;
	string role;
	string birthday;
	string gender;

public:
	User(string uId, string uName, string uRole);
	virtual ~User() {}

	string getID() const;
	string getName() const;
	string getRole() const;

	bool setName(string n);

	virtual void displayMenu() = 0;


	// khoa: check input login
	User(std::string uId, std::string uPass, std::string uName, std::string uGender, std::string uBirthday)
        : id(uId), pass(uPass), name(uName), gender(uGender), birthday(uBirthday) {};

	bool checkPassword(const std::string& inputPass) const {return this->pass == inputPass;}
};
