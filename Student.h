#pragma once
#include <vector>
#include "User.h"
#include <string>

using namespace std;

class Course;

class Student : public User
{
private:
	string major;
	vector<Course*> enrolledCourses;
	string field;
public:
	Student(string uId, string name, string major);
	bool enrollCourse(Course* c);
	bool leaveCourse(Course* c);
	void showCourse() const;
	void showGrade() const;
	string getMajor() const;

	void displayMenu() override;


	// khoa: check login
	Student(std::string sId, std::string sPass, std::string sName, 
            std::string sGender, std::string sBirthday, std::string sField)
        : User(sId, sPass, sName, sGender, sBirthday), field(sField){}
};
