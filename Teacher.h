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

    void viewStudentsInClass(const string& targetClassId, const Database& db);
    void addClassId(string classId);
    void display(Database& db);
};
