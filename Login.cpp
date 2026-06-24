#include "Login.h"
#include <iostream>
#include <fstream>
using namespace std;

Login::Login() {
    importAllData();
}

// Hàm tổng điều phối
void Login::importAllData() {
    // importAdmins();
    // importCourses();
    importStudents();
    // importTeachers();
    // importGrades();
    cout << "Toàn bộ dữ liệu đã nạp xong vào!\n";
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

void Login::importStudents() {
    ifstream f("data/student.txt");
    string id, pass, name, gender, birthday, field;
    if (f.is_open()) {
        while (f >> id >> pass >> name >> gender >> birthday >> field) {
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

void Login::run()
{
    std::string inputId;
    std::string inputPass;

    while(true)
    {

        std::cout << "Id: "; 
        std::cin >> inputId;

        std::cout << "Password: "; 
        std::cin >> inputPass;

        bool isFound = false;

        for (const auto& student : studentList) 
        {
            if (student.getID() == inputId) 
            { 
                if (student.checkPassword(inputPass)) 
                {
                    std::cout << "\n[HỆ THỐNG]: Đăng nhập thành công! Xin chào " << student.getName() << ".\n";
                    isFound = true;
                    return;
                }
            }
        }
        if (!isFound) 
        {
            std::cout << "[THẤT BẠI]: Sai mã số sinh viên hoặc mật khẩu. Vui lòng thử lại!\n";
        }
    }
}