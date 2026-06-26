#pragma once
#include <string>
using namespace std;

class Course
{
private:
	string courseID;
	string courseName;
	
public:
	Course(string id, string name);

	string getCourseID() const;
	string getCourseName() const;
	void setName(string newName);
};
