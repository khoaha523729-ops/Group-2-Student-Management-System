#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

using namespace std;

class Admin
{
private:
    string aId;
    string aName;
    string aPass;
    
    // Con trỏ kết nối tới các vector tổng trong class Database
    vector<Course>* managingCourses;
    vector<Student>* managingStudents;
    vector<Teacher>* managingTeachers;

public:
    // Constructor và các hàm kiểm tra thông tin tài khoản
    Admin(string aId, string pass, string aName);
    string getID() const;
    string getName() const;
    bool checkPassword(const string& inputPass) const;

    // Các hàm xử lý Menu hệ thống
    void adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers);
    void setData(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers);

    void courseSubMenu();
    void studentSubMenu();
    void teacherSubMenu();

    // Các hàm nghiệp vụ quản lý Môn học (Course)
    void addCourse();
    void editCourse();
    
    // Các hàm nghiệp vụ quản lý Sinh viên (Student)
    void addStudent();
    void editStudent();
    
    // Các hàm nghiệp vụ quản lý Giáo viên (Teacher)
    void addTeacher();
    void editTeacher();
    
    void editInfo();
};