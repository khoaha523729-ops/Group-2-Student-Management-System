#include "Student.h"
#include <iostream>

Student::Student(string id, string pass, string name, string gender, string birthday, string major)
    : User(id, pass, name, gender, birthday), major(major)
{
}

string Student::getMajor() const
{
    return major;
}

void Student::display()
{
    cout << "\n===== STUDENT MENU =====\n";
    cout << "1. Hien thi cac khoa hoc\n";
    cout << "2. Hien thi diem\n";
    cout << "3. Logout\n";
}
