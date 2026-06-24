#pragma once
#include "User.h"
#include <string>

using namespace std;

class Student : public User
{
private:
    string fieldOfStudy;
public:
    Student(string id, string pass, string name, string gender, string birthday, string field);
    string getFieldOfStudy() const;

    void display() override;
};
