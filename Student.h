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

	void display() override;


	// import file student.txt
	Student(string sId, string sPass, string sName, 
            string sGender, string sBirthday, string sField)
        : User(sId, sPass, sName, sGender, sBirthday), field(sField){}

	
	// thieu constructor hien tat ca course hien co
};
