#include "Database.h"
#include <iostream>
#include <fstream>

Database::Database() {
    importAllData();
}

void Database::importAllData() {
    // importAdmins();
    // importCourses();
    importStudents();
    // importTeachers();
    // importGrades();
}

// void Login::importAdmins() {
//     ifstream f("data/admin.txt");
//     string id, pass, name;
//     if (f.is_open()) {
//         while (f >> id >> pass >> name) {
//             adminList.push_back(Admin(id, pass, name));
//         }
//         f.close();
//     } else {
//         cerr << "[LỖI]: Không mở được file admin.txt\n";
//     }
// }

// void Login::importCourses() {
//     ifstream f("data/course.txt");
//     string id, name;
//     if (f.is_open()) {
//         while (f >> id >> name) {
//             courseList.push_back(Course(id, name));
//         }
//         f.close();
//     }
// }

void Database::importStudents() {
    ifstream f("data/student.txt");
    string id, pass, name, gender, birthday, field;
    if (f.is_open()) {
        while (f >> id >> pass >> name >> gender >> birthday >> field) {
            
            for (char &c : name) {
                if (c == '_') {
                    c = ' '; // Nếu là '_' thì đổi thành khoảng trắng
                }
            }
            
            studentList.push_back(Student(id, pass, name, gender, birthday, field));
        }
        f.close();
    }
}

// void Login::importTeachers() {
//     ifstream f("data/teacher.txt");
//     string id, pass, name, birthday, classIdsList;
//     if (f.is_open()) {
//         while (f >> id >> pass >> name >> birthday >> classIdsList) {
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

// void Login::importGrades() {
//     ifstream f("data/grade.txt");
//     string sId, classId;
//     double process, endCourse;
//     if (f.is_open()) {
//         while (f >> sId >> classId >> process >> endCourse) {
//             gradeList.push_back(GradeRecord(sId, classId, process, endCourse));
//         }
//         f.close();
//     }
// }