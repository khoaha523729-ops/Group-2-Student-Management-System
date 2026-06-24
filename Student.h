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
public:
	Student(string uId, string name, string major);
	bool enrollCourse(Course* c);
	bool leaveCourse(Course* c);
	void showCourse() const;
	void showGrade() const;
	string getMajor() const;

	void displayMenu() override;
};
