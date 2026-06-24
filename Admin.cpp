#include "Admin.h"
#include <iostream>
#include <fstream>   
#include <windows.h> 

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
Admin::~Admin() {
    cout << "\n[He thong] Dang tu dong luu du lieu vao thu muc data..." << endl;

    if (managingCourses != nullptr) {
        ofstream f("data/course.txt"); 
        if (f.is_open()) {
            // Dung vong lap for binh thuong
            for (int i = 0; i < managingCourses->size(); i++) {
                f << managingCourses->at(i).id << "," << managingCourses->at(i).name << "\n"; 
            }
            f.close();
        }
    }

    if (managingStudents != nullptr) {
        ofstream f("data/student.txt");
        if (f.is_open()) {
            for (int i = 0; i < managingStudents->size(); i++) {
                f << managingStudents->at(i).id << "," 
                  << managingStudents->at(i).name << "," 
                  << managingStudents->at(i).dob << "," 
                  << managingStudents->at(i).sex << "," 
                  << managingStudents->at(i).field << "\n";
            }
            f.close();
        }
    }

    if (managingTeachers != nullptr) {
        ofstream f("data/teacher.txt");
        if (f.is_open()) {
            for (int i = 0; i < managingTeachers->size(); i++) {
                f << managingTeachers->at(i).id << "," << managingTeachers->at(i).name << "\n";
            }
            f.close();
        }
    }
    cout << "[He thong] Da luu data thanh cong!" << endl;
}

void Admin::adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {
    SetConsoleOutputCP(CP_UTF8); 
    
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
    Course c;
    cout << "Enter Course ID: "; cin >> c.id;
    cout << "Enter Course Name: "; cin.ignore(); getline(cin, c.name);
    managingCourses->push_back(c);
    cout << "Added successfully!" << endl;
}

void Admin::editCourse() {
    string id;
    cout << "Enter Course ID to edit: "; cin >> id;
    for (int i = 0; i < managingCourses->size(); i++) {
        if (managingCourses->at(i).id == id) {
            cout << "Enter new Name: "; cin.ignore(); getline(cin, managingCourses->at(i).name);
            cout << "Updated successfully!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void Admin::addStudent() {
    Student s;
    cout << "Enter Student ID: "; cin >> s.id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, s.name);
    cout << "Enter DOB: "; getline(cin, s.dob);
    cout << "Enter Sex: "; getline(cin, s.sex);
    cout << "Enter Field: "; getline(cin, s.field);
    managingStudents->push_back(s);
    cout << "Added successfully!" << endl;
}

void Admin::editStudent() {
    string id;
    cout << "Enter Student ID to edit: "; cin >> id;
    for (int i = 0; i < managingStudents->size(); i++) {
        if (managingStudents->at(i).id == id) {
            cout << "New Name: "; cin.ignore(); getline(cin, managingStudents->at(i).name);
            cout << "New DOB: "; getline(cin, managingStudents->at(i).dob);
            cout << "New Sex: "; getline(cin, managingStudents->at(i).sex);
            cout << "New Field: "; getline(cin, managingStudents->at(i).field);
            cout << "Updated successfully!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void Admin::addTeacher() {
    Teacher t;
    cout << "Enter Teacher ID: "; cin >> t.id;
    cout << "Enter Teacher Name: "; cin.ignore(); getline(cin, t.name);
    managingTeachers->push_back(t);
    cout << "Added successfully!" << endl;
}

void Admin::editTeacher() {
    string id;
    cout << "Enter Teacher ID to edit: "; cin >> id;
    for (int i = 0; i < managingTeachers->size(); i++) {
        if (managingTeachers->at(i).id == id) {
            cout << "Enter new Name: "; cin.ignore(); getline(cin, managingTeachers->at(i).name);
            cout << "Updated successfully!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}
