#pragma once
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Teacher : public User
{
private:
    vector<string> classIds; 

public:
    void display() override;

    Teacher(string tId, string tPass, string tName, string tBirthday)
        : User(tId, tPass, tName, "", tBirthday) {}

    void addClassId(string classId);

    vector<string> getClassIds() { return classIds; }
};