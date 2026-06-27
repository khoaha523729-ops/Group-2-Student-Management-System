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
    importTeachers();
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

void Database::importTeachers() {
    ifstream f("data/teacher.txt");
    string id, pass, name, gender, birthday, classIdsList;
    
    if (f.is_open()) {
        while (f >> id >> pass >> name >> gender >> birthday >> classIdsList) {
            for (char &c : name) { if (c == '_') { c = ' '; } }
            vector<string> tempClassIds;
            stringstream ss(classIdsList);
            string singleClassId;
            while (getline(ss, singleClassId, ',')) {
                tempClassIds.push_back(singleClassId);
            }
            Teacher t(id, pass, name, gender, birthday, tempClassIds);

            teacherList.push_back(t);
        }
        f.close();
    }
}

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

void Database::exportGrades()
{
    // Mở file ở chế độ ghi (mặc định sẽ ghi đè xóa dữ liệu cũ để cập nhật mới)
    ofstream f("data/grade.txt"); 
    
    if (f.is_open()) {
        // Duyệt qua từng bản ghi điểm trong hệ thống dựa trên vector gradeList của Database
        for (const auto& grade : gradeList) {
            // Ghi dữ liệu ra file theo đúng thứ tự: mssv -> mã lớp -> điểm quá trình -> điểm cuối kỳ
            // Sử dụng các hàm Getter của class GradeRecord (lưu ý chỉnh tên hàm cho đúng với class của anh)
            f << grade.getStudentId() << " " 
              << grade.getClassId() << " " 
              << grade.getProcessScore() << " " 
              << grade.getEndCourseScore() << "\n"; 
        }
        
        f.close(); // Đóng file sau khi ghi xong
        cout << "Da luu va dong bo du lieu diem thanh cong.\n";
    } else {
        // Thông báo nếu hệ thống không tìm thấy thư mục hoặc file bị khóa
        cout << "[Error] Du lieu luu khong thanh cong!\n";
    }
}
