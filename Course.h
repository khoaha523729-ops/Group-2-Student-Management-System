#pragma once
#include <string>

class Course
{
private:
	std::string courseID;
	std::string courseName;
public:
	Course(std::string id, std::string name);

	std::string getCourseID() const;
	std::string getCourseName() const;
};
