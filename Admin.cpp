#define NOMINMAX 
#include <windows.h> 
#include <iostream>
#include <fstream>   
#include <string>
#include "Admin.h"

using namespace std;

Admin::Admin(string aId, string pass, string aName) 
{
    this->aId = aId;
    this->aPass = pass;
    this->aName = aName;
}

string Admin::getID() const { return aId; }
string Admin::getName() const { return aName; }
bool Admin::checkPassword(const string& inputPass) const { return aPass == inputPass; }

void Admin::editInfo() {
    cout << "\n[He thong] Dang tu dong luu du lieu vao thu muc data..." << endl;

    if (managingCourses != nullptr) {
        ofstream f("data/course.txt"); 
        if (f.is_open()) {
            for (size_t i = 0; i < managingCourses->size(); i++) {
                f << managingCourses->at(i).getCourseID() << "," << managingCourses->at(i).getCourseName() << "\n"; 
            }
            f.close();
        }
    }

    if (managingStudents != nullptr) {
        ofstream f("data/student.txt");
        if (f.is_open()) {
            for (size_t i = 0; i < managingStudents->size(); i++) {
                f << managingStudents->at(i).getID() << "," 
                  << managingStudents->at(i).getName() << "," 
                  << managingStudents->at(i).getBirthday() << "," 
                  << managingStudents->at(i).getGender() << "," 
                  << managingStudents->at(i).getMajor() << "\n";
            }
            f.close();
        }
    }

    if (managingTeachers != nullptr) {
        ofstream f("data/teacher.txt");
        if (f.is_open()) {
            for (size_t i = 0; i < managingTeachers->size(); i++) {
                f << managingTeachers->at(i).getID() << "," << managingTeachers->at(i).getName() << "\n";
            }
            f.close();
        }
    }
    cout << "[He thong] Da luu data thanh cong!" << endl;
}

void Admin::setData(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {
    this->managingCourses = &courses;
    this->managingStudents = &students;
    this->managingTeachers = &teachers;
}

void Admin::adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {
    setData(courses, students, teachers); 
    int choice;
    while (true) {
        cout << "\n===== ADMIN MAIN MENU =====" << endl;
        cout << "1. Quan ly mon hoc (Course)" << endl;
        cout << "2. Quan ly sinh vien (Student)" << endl;
        cout << "3. Quan ly giao vien (Teacher)" << endl;
        cout << "0. Dang xuat" << endl;
        cout << "Chon: "; cin >> choice;

        if (choice == 0) break;
        switch (choice) {
            case 1: courseSubMenu(); break;
            case 2: studentSubMenu(); break;
            case 3: teacherSubMenu(); break;
            default: cout << "Lua chon sai!" << endl;
        }
    }
    editInfo();
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
    string inputID, inputName;
    cout << "\n----- THEM MON HOC MOI -----" << endl;
    cout << "Nhap Ma mon hoc: "; cin >> inputID;
    cin.ignore(1000, '\n');

    for (size_t i = 0; i < managingCourses->size(); i++) {
        if (managingCourses->at(i).getCourseID() == inputID) {
            cout << "[Loi] Ma mon hoc " << inputID << " da ton tai trong he thong!" << endl;
            return; 
        }
    }

    cout << "Nhap Ten mon hoc: "; getline(cin, inputName);
    managingCourses->emplace_back(inputID, inputName);
    cout << "=> Them mon hoc thanh cong!" << endl;
}

void Admin::editCourse() {
    string id;
    cout << "\n----- SUA THONG TIN MON HOC -----" << endl;
    cout << "Nhap Ma mon hoc can sua: "; cin >> id;
    cin.ignore(1000, '\n');

    bool found = false;
    for (size_t i = 0; i < managingCourses->size(); i++) {
        if (managingCourses->at(i).getCourseID() == id) {
            string newName;
            cout << "Mon hoc hien tai: " << managingCourses->at(i).getCourseName() << endl;
            cout << "Nhap Ten moi: "; getline(cin, newName);

            managingCourses->at(i).setName(newName);
            cout << "=> Cap nhat ten mon hoc thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "[Loi] Khong tim thay mon hoc co ma: " << id << endl;
}

void Admin::addStudent() {
    string inputId, inputName, inputGender, inputBirthday, inputMajor;
    string defaultPass = "123";
    
    cout << "\n----- THEM SINH VIEN MOI -----" << endl;
    cout << "Nhap ID: "; cin >> inputId; 
    cin.ignore(1000, '\n'); 

    for (size_t i = 0; i < managingStudents->size(); i++) {
        if (managingStudents->at(i).getID() == inputId) {
            cout << "[Loi] Ma sinh vien " << inputId << " da ton tai trong he thong!" << endl;
            return;
        }
    }

    cout << "Nhap ten: "; getline(cin, inputName);
    cout << "Gioi tinh: "; cin >> inputGender;
    cout << "Ngay sinh (dd/mm/yyyy): "; cin >> inputBirthday;
    cin.ignore(1000, '\n');
    cout << "Chuyen nganh: "; getline(cin, inputMajor);

    managingStudents->push_back(Student(inputId, defaultPass, inputName, inputGender, inputBirthday, inputMajor));
    cout << "=> Them sinh vien thanh cong!" << endl;
}

void Admin::editStudent() {
    string id;
    cout << "\n----- SUA THONG TIN SINH VIEN -----" << endl;
    cout << "Nhap Student ID can sua: "; cin >> id;
    cin.ignore(1000, '\n');
    bool found = false;
    for (size_t i = 0; i < managingStudents->size(); i++) {
        if (managingStudents->at(i).getID() == id) {
            string newName;
            cout << "Sinh vien hien tai: " << managingStudents->at(i).getName() << endl;
            cout << "Nhap ten moi: "; getline(cin, newName);
            
            User* userPtr = &(managingStudents->at(i));
            userPtr->setName(newName); 
            
            cout << "=> Cap nhat ten thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "[Loi] Khong tim thay sinh vien ID: " << id << endl;
}

void Admin::addTeacher() {
    string inputId, inputName, inputGender, inputBirthday;
    vector<string> inputClassId;
    string defaultPass = "123"; 

    cout << "\n----- THEM GIAO VIEN MOI -----" << endl;
    cout << "Nhap ID Giao vien: "; cin >> inputId;
    cin.ignore(1000, '\n'); 
    cout << "Nhap Ho ten: "; getline(cin, inputName);
    cout << "Nhap Gioi tinh: "; cin >> inputGender;
    cout << "Nhap Ngay sinh (dd/mm/yyyy): "; cin >> inputBirthday;

    managingTeachers->push_back(Teacher(inputId, defaultPass, inputName, inputGender, inputBirthday, inputClassId));

    cout << "=> Them giao vien thanh cong!" << endl;
}

void Admin::editTeacher() {
    string id;
    cout << "\n----- SUA THONG TIN GIAO VIEN -----" << endl;
    cout << "Nhap Teacher ID can sua: "; cin >> id;
    cin.ignore(1000, '\n'); 

    bool found = false;
    for (size_t i = 0; i < managingTeachers->size(); i++) {
        if (managingTeachers->at(i).getID() == id) {
            string newName, newGender, newBirthday;
            cout << "Tim thay giao vien: " << managingTeachers->at(i).getName() << endl;
            
            cout << "Nhap Ten moi: "; getline(cin, newName);
            cout << "Nhap Gioi tinh moi: "; cin >> newGender;
            cin.ignore(1000, '\n');
            cout << "Nhap Ngay sinh moi: "; cin >> newBirthday;

            User* userPtr = &(managingTeachers->at(i));
            userPtr->setName(newName);
            userPtr->setGender(newGender);
            userPtr->setBirthday(newBirthday);

            cout << "=> Cap nhat thong tin giao vien thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "[Loi] Khong tim thay giao vien co ID: " << id << endl;
}