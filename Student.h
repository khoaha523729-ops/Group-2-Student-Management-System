#pragma once
#include "User.h"
#include <string>

using namespace std;

class Database;

class Student : public User
{
private:
    string major;
public:
    Student(string id, string pass, string name, string gender, string birthday, string major);
    string getMajor() const;
    string inputCourseID() const;
    void display(Database& db);
    void showAllCourses(const Database& db) const;
    void showCourseGrade(const Database& db, const string& courseID) const;
    void showStudentRecord() const;
};