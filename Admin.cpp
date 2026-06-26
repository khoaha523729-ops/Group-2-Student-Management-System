#include "Admin.h"
#include <iostream>
#include <fstream>   
#include <windows.h> 
#include <string>


using namespace std;

Admin::Admin(string aId, string pass, string aName) 
{
    this->aId = aId;
    this->aPass = pass;
    this->aName = aName;
}

string Admin::getID() const
{
    return aId;
}

string Admin::getName() const
{
    return aName;
}

bool Admin::checkPassword(const string& inputPass) const
{
    return aPass == inputPass; 
}

// Hàm hủy lưu file
// Admin::~Admin() {
//     cout << "\n[He thong] Dang tu dong luu du lieu vao thu muc data..." << endl;

//     if (managingCourses != nullptr) {
//         ofstream f("data/course.txt"); 
//         if (f.is_open()) {
//             // Dung vong lap for binh thuong
//             for (int i = 0; i < managingCourses->size(); i++) {
//                 f << managingCourses->at(i).id << "," << managingCourses->at(i).name << "\n"; 
//             }
//             f.close();
//         }
//     }

//     if (managingStudents != nullptr) {
//         ofstream f("data/student.txt");
//         if (f.is_open()) {
//             for (int i = 0; i < managingStudents->size(); i++) {
//                 f << managingStudents->at(i).id << "," 
//                   << managingStudents->at(i).name << "," 
//                   << managingStudents->at(i).dob << "," 
//                   << managingStudents->at(i).sex << "," 
//                   << managingStudents->at(i).field << "\n";
//             }
//             f.close();
//         }
//     }

//     if (managingTeachers != nullptr) {
//         ofstream f("data/teacher.txt");
//         if (f.is_open()) {
//             for (int i = 0; i < managingTeachers->size(); i++) {
//                 f << managingTeachers->at(i).id << "," << managingTeachers->at(i).name << "\n";
//             }
//             f.close();
//         }
//     }
//     cout << "[He thong] Da luu data thanh cong!" << endl;
// }

void Admin::adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {

    this->managingCourses = &courses;
    this->managingStudents = &students;
    this->managingTeachers = &teachers;

    int choice;
    do {
        cout << "\n-----------------------------" << endl;
        cout << "=== MENU ADMIN (" << aName << ") ===" << endl;
        cout << "1. Manage Course (Add/Edit)" << endl;
        cout << "2. Manage Student (Add/Edit)" << endl;
        cout << "3. Manage Teacher (Add/Edit)" << endl;
        cout << "0. Return (Luu du lieu & Thoat)" << endl;
        cout << "Input choice: ";
        cin >> choice;

        switch (choice) {
            case 1: courseSubMenu(); break;
            case 2: studentSubMenu(); break;
            case 3: teacherSubMenu(); break;
            case 0: break;
            default: cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);
}

void Admin::courseSubMenu() {
    int choice;
    cout << "\n[COURSE MENU]\n1. Add Course\n2. Edit Course\n0. Return\nChoice: ";
    cin >> choice;
    if (choice == 1) addCourse();
    else if (choice == 2) editCourse();
}

void Admin::studentSubMenu() {
    int choice;
    cout << "\n[STUDENT MENU]\n1. Add Student\n2. Edit Student\n0. Return\nChoice: ";
    cin >> choice;
    if (choice == 1) addStudent();
    else if (choice == 2) editStudent();
}

void Admin::teacherSubMenu() {
    int choice;
    cout << "\n[TEACHER MENU]\n1. Add Teacher\n2. Edit Teacher\n0. Return\nChoice: ";
    cin >> choice;
    if (choice == 1) addTeacher();
    else if (choice == 2) editTeacher();
}

void Admin::addCourse() {
    string inputID;
    string inputName;
    cout << "Enter Course ID: "; cin >> inputID; cin.ignore(1000, '\n');
    cout << "Enter Course Name: "; getline(cin, inputName);
    managingCourses->emplace_back(inputID, inputName);
    cout << "Added successfully!" << endl;
}

void Admin::editCourse() {
    string id;
    cout << "Enter Course ID to edit: "; 
    cin >> id;
    cin.ignore(1000, '\n'); 
    for (int i = 0; i < managingCourses->size(); i++) {
        if (managingCourses->at(i).getCourseID() == id) { 
            
            string newName;
            cout << "Enter new Name: "; 
            getline(cin, newName);
            managingCourses->at(i).setName(newName); 

            cout << "Updated successfully!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void Admin::addStudent() {
    string inputId, inputName, inputGender, inputBirthday, inputMajor;
    string defaultPass = "123"; // Mật khẩu mặc định khi admin tạo tài khoản

    cout << "Enter Student ID: "; 
    cin >> inputId;
    cin.ignore(1000, '\n');

    cout << "Enter Name: "; getline(cin, inputName);
    cout << "Enter DOB (Birthday): "; getline(cin, inputBirthday);
    cout << "Enter Sex (Gender): "; getline(cin, inputGender);
    cout << "Enter Field (Major): "; getline(cin, inputMajor);

    managingStudents->emplace_back(inputId, defaultPass, inputName, inputGender, inputBirthday, inputMajor);
    
    cout << "Added successfully!" << endl;
}

void Admin::editStudent() {
    string id;
    cout << "Enter Student ID to edit: "; 
    cin >> id;
    cin.ignore(1000, '\n'); // Đưa ignore lên đây để bảo vệ toàn bộ các lệnh getline phía dưới

    for (int i = 0; i < managingStudents->size(); i++) {
        // Dùng getID() có sẵn từ lớp cha User
        if (managingStudents->at(i).getID() == id) {
            string newName, newBirthday, newGender, newMajor;

            cout << "New Name: "; getline(cin, newName);
            cout << "New DOB (Birthday): "; getline(cin, newBirthday);
            cout << "New Sex (Gender): "; getline(cin, newGender);
            cout << "New Field (Major): "; getline(cin, newMajor);

            // Gọi các hàm Setter để cập nhật dữ liệu vào vector gốc
            managingStudents->at(i).setName(newName);
            managingStudents->at(i).setBirthday(newBirthday);
            managingStudents->at(i).setGender(newGender);
            managingStudents->at(i).setMajor(newMajor);

            cout << "Updated successfully!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void Admin::addTeacher() {
    string inputId, inputName;
    string defaultPass = "123"; 
    string defaultBirthday = "01/01/1990"; 

    cout << "Enter Teacher ID: "; 
    cin >> inputId;
    cin.ignore(1000, '\n'); 

    cout << "Enter Teacher Name: "; getline(cin, inputName);

    managingTeachers->emplace_back(inputId, defaultPass, inputName, defaultBirthday);
    
    cout << "Added successfully!" << endl;
}

void Admin::editTeacher() {
    string id;
    cout << "Enter Teacher ID to edit: "; 
    cin >> id;
    cin.ignore(1000, '\n'); 

    for (int i = 0; i < managingTeachers->size(); i++) {
        if (managingTeachers->at(i).getID() == id) {
            string newName;
            cout << "Enter new Name: "; 
            getline(cin, newName);
            managingTeachers->at(i).setName(newName); 
            cout << "Updated successfully!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}
