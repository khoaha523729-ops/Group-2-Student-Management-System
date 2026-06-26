#pragma once
#include <string>
#include <vector>
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "GradeRecord.h"

using namespace std;


class Database
{
    public:
    // Lưu dữ liệu vào project
    vector<Admin> adminList;
    vector<Student> studentList;
    vector<Teacher> teacherList; 
    vector<Course> courseList;
    vector<GradeRecord> gradeList;

    // Đọc từng file 
    void importAdmins();
    void importCourses();
    void importStudents();
    void importTeachers();
    void importGrades();
    void importAllData();
    
    Database();
};