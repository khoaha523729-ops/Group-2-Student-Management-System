#include "Student.h"
#include "Database.h"
#include <iostream>

Student::Student(string id, string pass, string name, string gender, string birthday, string major, Database& db)
    : User(id, pass, name, gender, birthday), major(major)
{
    cout << "\n===== ALL COURSES =====\n";

    for (int i = 0; i < db.courseList.size(); i++)
    {
        cout << db.courseList[i].getCourseID() << " "
            << db.courseList[i].getCourseName() << endl;
    }

    cout << endl;
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

void Student::showStudentRecord() const
{
    cout << "\n===== STUDENT RECORD =====\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << birthday << endl;
    cout << "Major: " << major << endl;
}
