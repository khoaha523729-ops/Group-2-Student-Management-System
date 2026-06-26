#include "Student.h"
#include "Database.h"
#include <iostream>
#include "Database.h"

using namespace std;

Student::Student(string id, string pass, string name, string gender, string birthday, string major)
    : User(id, pass, name, gender, birthday), major(major)
{
}

string Student::getMajor() const
{
    return major;
}

void Student::display(Database& db)
{
    cout << "\n===== STUDENT MENU =====\n";
    cout << "1. Chon mon hoc\n";
    cout << "2. Hien thi diem\n";
    cout << "3. Logout\n";
}

void Student::showAllCourses(const Database& db) const
{
    cout << "\n===== COURSE LIST =====\n";
    for (int i = 0; i < db.courseList.size(); i++)
    {
        cout << db.courseList[i].getCourseID() << " " << db.courseList[i].getCourseName() << endl;
    }
}

string Student::inputCourseID() const
{
    string courseID;
    cout << "Nhap ma mon hoc: ";
    cin >> courseID;

    return courseID;
}

void Student::showCourseGrade(const Database& db, const string& courseID) const
{
    for (int i = 0; i < db.gradeList.size(); i++)
    {
        if (db.gradeList[i].getStudentId() == id && db.gradeList[i].getClassId() == courseID)
        {
            cout << "\n===== GRADE =====\n";
            cout << "Process Score: " << db.gradeList[i].getProcessScore() << endl;
            cout << "End Course Score: " << db.gradeList[i].getEndCourseScore() << endl;
            cout << "Final Score: " << db.gradeList[i].getFinalScore() << endl;

            return;
        }
    }

    cout << "Khong tim thay diem cua mon hoc nay.\n";
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


void Student::setMajor(const string& newMajor) { this->major = newMajor; }
