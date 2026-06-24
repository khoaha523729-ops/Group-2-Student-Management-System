#include "Course.h"

Course::Course(std::string id, std::string name) : courseID(id), courseName(name)
{
}

std::string Course::getCourseID() const
{
	return courseID;
}

std::string Course::getCourseName() const
{
	return courseName;
}
