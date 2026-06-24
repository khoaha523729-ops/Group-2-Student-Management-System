#include "Student.h"
#include <iostream>

Student::Student(string uId, string name, string m) : User(uId, name, "Student"), major(m)
{

}

bool Student::enrollCourse(Course* c)
{
    for (int i = 0; i < enrolledCourses.size(); i++)
    {
        if (enrolledCourses[i] == c)
            return false;
    }
    enrolledCourses.push_back(c);
    return true;
}

bool Student::leaveCourse(Course* c)
{
    for (auto it = enrolledCourses.begin();
        it != enrolledCourses.end();
        ++it)
    {
        if (*it == c)
        {
            enrolledCourses.erase(it);
            return true;
        }
    }
    return false;
}

void Student::showCourse() const
{
    cout << "\nDanh sach mon da dang ky:\n";

    for (const auto& c : enrolledCourses)
    {
        cout << "- " << c << endl;
    }
}

void Student::showGrade() const
{
    cout << "chx co\n";
}

string Student::getMajor() const
{
    return major;
}

void Student::display()
{
    cout << "\n===== STUDENT MENU =====\n";
    cout << "1. Thông tin cá nhân.\n";
    cout << "0. Thoát.\n";
    cout << "Nhập mã học phần để xem đểm: ";

    // chua co ham cin 
}


