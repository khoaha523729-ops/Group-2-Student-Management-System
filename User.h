#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string id;
	string name;
	string role;
public:
	User(string uId, string uName, string uRole);
	virtual ~User() {}

	string getID() const;
	string getName() const;
	string getRole() const;

	bool setName(string n);

	virtual void displayMenu() = 0;
};
