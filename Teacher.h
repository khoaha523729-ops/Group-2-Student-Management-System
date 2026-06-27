#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"



using namespace std;

class Teacher : public User
{
private:

    vector<string> classIds;

public:
    Teacher(string tId, string tPass, string tName,string tgender, string tBirthday, vector<string> tclassIds);

    void viewStudentsInClass(const string& targetClassId, Database& db);
    void editGrade(const string& targetClassId, const string& studentId, Database& db);
    void display(Database& db);
};
