#pragma once
#include "User.h"
#include <string>

using namespace std;

class Student : public User
{
private:
    string major;
public:
    Student(string id, string pass, string name, string gender, string birthday, string major);
    string getMajor() const;
    void showStudentRecord() const;

    void display() override;
};
