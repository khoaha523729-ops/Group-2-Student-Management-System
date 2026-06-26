#include "Database.h"
#include <iostream>
#include <fstream>
#include <sstream>

Database::Database() {
    importAllData();
}

void Database::importAllData() {
    // importAdmins();
    importCourses();
    importStudents();
    // importTeachers();
    importGrades();
    
}

// void Database::importAdmins() {
//     ifstream f("data/admin.txt");
//     string id, pass, name;
//     if (f.is_open()) {
//         while (f >> id >> pass >> name) {
//             for (char &c : name) {if (c == '_') {c = ' ';}}
//             adminList.push_back(Admin(id, pass, name));
//         }
//         f.close();
//     }
// }

void Database::importCourses() {
    ifstream f("data/course.txt");
    string id, name;
    if (f.is_open()) {
        while (f >> id >> name) {
            for (char &c : name) {if (c == '_') {c = ' ';}}
            courseList.push_back(Course(id, name));
        }
        f.close();
    }
}

void Database::importStudents() {
    ifstream f("data/student.txt");
    string id, pass, name, gender, birthday, major;
    if (f.is_open()) {
        while (f >> id >> pass >> name >> gender >> birthday >> major) {
            for (char &c : name) {if (c == '_') {c = ' ';}}
            studentList.push_back(Student(id, pass, name, gender, birthday, major));
        }
        f.close();
    }
}

// void Database::importTeachers() {
//     ifstream f("data/teacher.txt");
//     string id, pass, name, gender, birthday, classIdsList;
//     if (f.is_open()) {
//         while (f >> id >> pass >> name >> gender >> birthday >> classIdsList) {
//             for (char &c : name) {if (c == '_') {c = ' ';}}
//             Teacher t(id, pass, name, birthday);
//             stringstream ss(classIdsList);
//             string singleClassId;
//             while (getline(ss, singleClassId, ',')) {
//                 t.addClassId(singleClassId);
//             }
//             teacherList.push_back(t);
            
//         }
//         f.close();
//     }
// }

void Database::importGrades() {
    ifstream f("data/grade.txt");
    string sId, classId;
    double process, endCourse;
    if (f.is_open()) {
        while (f >> sId >> classId >> process >> endCourse) {
            gradeList.push_back(GradeRecord(sId, classId, process, endCourse));
        }
        f.close();
    }
}

