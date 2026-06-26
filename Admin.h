// #pragma once
// #include <vector>
// #include <string>
// #include <iostream>
// #include "Student.h"
// #include "Teacher.h"
// #include "Course.h"

// using namespace std;

// class Database;

// class Admin
// {
// private:
//     string aId;
//     string aName;
//     string aPass;
//     vector<Course>* managingCourses;
//     vector<Student>* managingStudents;
//     vector<Teacher>* managingTeachers;

// public:
//     string getID() const;
//     string getName() const;
//     bool checkPassword(const string& inputPass) const;

//     void adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers);
//     void setData(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers);

//     void editCourse();
//     void editStudent();
//     void editTeacher();

//     void courseSubMenu();
//     void studentSubMenu();
//     void teacherSubMenu();
//     void addStudent();
//     void addCourse();
//     void addTeacher();
    
//     Admin(string aId, string pass, string name);
//     // ~Admin();
// };
