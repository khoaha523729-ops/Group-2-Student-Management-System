#pragma once
#include <vector>
#include <string>

using namespace std;

class Admin
{
private:
    string aId;
    string aName;
    string aPass;

public:

	//import file admin.txt
	Admin(string aId, string pass, string name){};
    string getID() const;
    string getName() const;
    bool checkPassword(const string& inputPass) const;
};

