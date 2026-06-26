#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"



using namespace std;

class Teacher : public User
{
private:
    string username;
    string password;
    string teacherId;
    string name;
    vector<string> classIds;

public:
    Teacher(string tId, string tPass, string tName, string tBirthday)
    : User(tId, tPass, tName, "", tBirthday) {}

    // Teacher();
    // Teacher(string user, string pass, string id, string teacherName);

    string getUsername() const;
    string getPassword() const;
    string getTeacherId() const;
    string getName() const;

    void addClassId(string classId);
    void display(Database& db);
};
