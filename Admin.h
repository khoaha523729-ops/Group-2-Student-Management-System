#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Database;

class Admin
{
private:
    string aId;
    string aName;
    string aPass;

public:
    Admin(string aId, string pass, string name) : aId(aId), aPass(pass), aName(name) {}
    string getID() const { return aId; }
    string getName() const { return aName; }
    bool checkPassword(const string& inputPass) const { return aPass == inputPass; }

    void adminMenu(Database& db);
    
    void editCourse(Database& db);
    void editStudent(Database& db);
    void editTeacher(Database& db);
};
